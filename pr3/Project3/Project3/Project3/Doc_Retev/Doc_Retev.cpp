
#include "Doc_retev.h"


void DocRet::createFileList() {

	for (int i = 0; i < 100; i++) {

		std::stringstream ss;
		std::string s;

		ss << "FileSet3/" << std::to_string(i) << ".txt";
		ss >> s;

		fileList.push_back(s);
		//std::cout << s << std::endl;
	}
}

void DocRet::createInvertIndex() {
	std::ifstream file1;
	
	for (int i = 0; i < fileList.size(); i++) {

		std::string s = fileList[i];
		file1.open(s);
		std::string line1;

		while (!file1.eof())
		{
			std::getline(file1, line1);

			//remove punctuation from the line
			line1 = removePuncFromLine(line1);

			//read word by word from the line
			std::istringstream iss(line1);
			std::string sub1;

			while (iss >> sub1)
			{
				char* c1 = &sub1[0];
				if (isupper(c1[0])) c1[0] = tolower(c1[0]);
				sub1 = c1;

				std::unordered_map<std::string, std::vector<std::string>>::const_iterator got = mymap.find(sub1);

				if (got == mymap.end()) {
					//std::cout << "not found";
					std::vector<std::string> vec1;
					vec1.push_back(s);
					std::pair<std::string, std::vector<std::string>> myshopping(sub1, vec1);
					mymap.insert(myshopping);
				}

				else{
					int j;
					for (j = 0; j<mymap[got->first].size() ;j++) {
						
						if (s.compare(mymap[got->first][j]) == 0)break;
					}
					if (j == mymap[got->first].size()) {
						mymap[got->first].push_back(s);
					}
				}

			}

		}
		file1.close();
	}
}

std::string DocRet::removePuncFromLine(std::string line1) {

	for (int i = 0, len = line1.size(); i < len; i++)
	{
		char c = line1.at(i);         // Get a char from string

									  // if it's NOT within these bounds, then it's not a character
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' '))) {

			line1.erase(i--, 1);
			len = line1.size();
		}
	}
	return line1;
}