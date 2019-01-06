#include "FindInclude.h"

using namespace std;

void FindInclude::readFile(string spath, string key) {
	std::ifstream file(spath);
	//std::ifstream file("C:/Users/nash/Documents/Visual Studio 2015/Projects/Sorting/Sorting/Hello.h");
	std::string line;
	

	while (!file.eof())
	{
		std::getline(file, line);
		//cout << line << endl;
		
		//read word by word from the line
		std::istringstream iss(line);
		std::string sub;
		iss >> sub;

		if (sub.compare("#include") == 0) {
			iss >> sub;

			char *csub = &sub[0];
			if (csub[0] == '"') {
				stringstream ss;
				string s;
				int i = 1;
				for (; i < strlen(csub) && csub[i] != '.' && csub[i] != '/'; i++) {
					
					ss << csub[i];

				}
				if (csub[i] == '/') {
					ss >> s;
					//cout << s << endl;

					//////
					std::unordered_map<std::string, std::vector<std::string>>::const_iterator got = mymap.find(key);

					if (got == mymap.end()) {
						//std::cout << "not found";
						std::vector<std::string> vec1;
						vec1.push_back(s);
						std::pair<std::string, std::vector<std::string>> myshopping(key, vec1);
						mymap.insert(myshopping);
					}

					else {

						mymap[got->first].push_back(s);
					}
				}
				
			}

		}

	}
}


void FindInclude::display_map() {
	for (auto it = mymap.begin(); it != mymap.end(); ++it) {
		std::cout << " " << it->first << ":";
		
		for (string s : it->second) {
			std::cout << "  " << s;
		}
		std::cout << std::endl;
	}
	

}

void FindInclude::set_map(string s) {
	std::vector<std::string> vec1;

	std::pair<std::string, std::vector<std::string>> myshopping(s, vec1);
	mymap.insert(myshopping);
}