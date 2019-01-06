
#include"test.h"


int main()
{
	
	Trie* t1 = new Trie();
	Test* t = new Test();

	DocRet* dr = new DocRet();
	printf("Reading files from fileset....please wait...");

	dr->createFileList();
	dr->createInvertIndex();

	/*for (std::unordered_map<std::string, std::vector<std::string>>::const_iterator it = dr->mymap.begin();
	it != dr->mymap.end(); ++it)
	{
	std::cout << it->first << " ";
	for (std::string s1 : it->second) {
	std::cout << s1 << " ";
	}
	std::cout << std::endl;
	}
*/
	printf("\n\n");
	// Construct dictionery trie
	std::ifstream file("dictionery.txt");
	std::string word;

	while (file >> word) {
		char* c1 = &word[0];
		t1->insert(c1);
	}

	file.close();
	
	// spell-check
	printf("1. Spell-check and word suggestions\n\n");

	file.open("test1.txt");
	std::string line;

	//doc retrieval
	std::vector<std::string> que1;
	
	while (!file.eof())
	{
		std::getline(file, line);

		line = t->removePuncFromLine(line);

		//read word by word from the line
		std::istringstream iss(line);
		std::string sub;

		while (iss >> sub)
		{
			SpellCheck* spc = new SpellCheck();
			char* c1 = &sub[0];
			if (isupper(c1[0])) c1[0] = tolower(c1[0]);
			sub = c1;

			if (!t1->search(c1)) {
				std::cout << "mis-spelled word ::: " << sub << std::endl;
				
				spc->misSpell(sub);//subs, ins nd delete

				while (spc->words.size() > 0 && spc->suggestions.size() < 10) {
					std::string s1 = spc->words.front();
					char* c2 = &s1[0];

					if (t1->search(c2)) {
						spc->suggestions.push_back(s1);
					}
					spc->words.pop();
				}
				std::cout << "suggestions::: " << std::endl;
				
				std::string str = spc->suggestions[0];
				for (std::string sugs : spc->suggestions) { std::cout << sugs << std::endl; }
				
				printf("\n");
				
				
				//time for the doc ret
				if (que1.empty()) {
					for (int i = 0; i<dr->mymap[str].size(); i++) {
						que1.push_back(dr->mymap[str][i]);
					}
				}//end of if queue empty
				else {
					for (int i = 0; i < que1.size(); i++) {
						int toggle = 0;
						for (int j = 0; j < dr->mymap[str].size(); j++) {
							if (que1[i] == dr->mymap[str][j]) {
								toggle = 1;
							}
						}
						//condition for match was not found
						if (toggle == 0) {
							que1.erase(que1.begin() + i);
						}
					}
				}//if queue not empty

			}//if it is a misspell
			else {
				
				if (que1.empty()) {
					for (int i = 0; i<dr->mymap[sub].size(); i++) {
						que1.push_back(dr->mymap[sub][i]);
					}
				}//end of if queue empty
				else {
					for (int i = 0; i < que1.size(); i++) {
						int toggle = 0;
						for (int j = 0; j < dr->mymap[sub].size(); j++) {
							if (que1[i] == dr->mymap[sub][j]) {
								toggle = 1;
							}
						}
						//condition for match was not found
						if (toggle == 0) {
							que1.erase(que1.begin() + i);
						}
					}
				}//if queue not empty


			}//if it is not a mis-spell, doc retev

		}//end of while word by word
		
	}//end of while line by line

	// Search for different keys
	//printf("%s --- %s\n", "the", output[t1->search("of")]);
	//printf("%s --- %s\n", "these", output[t1->search("ese")]);
	//printf("%s --- %s\n", "their", output[t1->search("a")]);
	//printf("%s --- %s\n", "thaw", output[t1->search("nk")]);

	printf("\n\n\n");
	printf("2. auto-completion for prefix-- \n");
	std::string input;
	printf("enter a prefix..eg. per, as etc.:\n");
	getline(std::cin, input);
	char* cin = &input[0];
	t1->autoComp(cin);
	
	//printing the queue in the end with all the intersected text file names
	printf("\n\n\n");
	printf("3. Doc-retrieval on all the words in the file\n");
	if (que1.empty()) {
		printf("No intersections were found for all words in file\n");
	}
	else {
		for (int i = 0; i<que1.size(); i++) {
			std::cout << que1[i] << std::endl;
		}
	}

	printf("\n\n\n");
	printf("3. Doc-retrieval on a few words in array...just to show that it is working\n");
	std::string sarray[3] = {"communications","small", "boud"};
	for (std::string sa : sarray) {
		SpellCheck* spc = new SpellCheck();
		char* c1 = &sa[0];
		if (isupper(c1[0])) c1[0] = tolower(c1[0]);
		sa = c1;

		if (!t1->search(c1)) {
			std::cout << "there is a mis-spelled word::: " << sa << std::endl;

			spc->misSpell(sa);//subs, ins nd delete

			while (spc->words.size() > 0 && spc->suggestions.size() < 10) {
				std::string s1 = spc->words.front();
				char* c2 = &s1[0];

				if (t1->search(c2)) {
					spc->suggestions.push_back(s1);
				}
				spc->words.pop();
			}
			std::cout << "1st suggestion picked up::: ";

			std::string str = spc->suggestions[0];
			std::cout << str << std::endl;

			printf("\n");


			//time for the doc ret
			if (que1.empty()) {
				for (int i = 0; i<dr->mymap[str].size(); i++) {
					que1.push_back(dr->mymap[str][i]);
				}
			}//end of if queue empty
			else {
				for (int i = 0; i < que1.size(); i++) {
					int toggle = 0;
					for (int j = 0; j < dr->mymap[str].size(); j++) {
						if (que1[i] == dr->mymap[str][j]) {
							toggle = 1;
						}
					}
					//condition for match was not found
					if (toggle == 0) {
						que1.erase(que1.begin() + i);
					}
				}
			}//if queue not empty

		}//if it is a misspell
		else {

			if (que1.empty()) {
				for (int i = 0; i<dr->mymap[sa].size(); i++) {
					que1.push_back(dr->mymap[sa][i]);
				}
			}//end of if queue empty
			else {
				for (int i = 0; i < que1.size(); i++) {
					int toggle = 0;
					for (int j = 0; j < dr->mymap[sa].size(); j++) {
						if (que1[i] == dr->mymap[sa][j]) {
							toggle = 1;
						}
					}
					//condition for match was not found
					if (toggle == 0) {
						que1.erase(que1.begin() + i);
					}
				}
			}//if queue not empty


		}//if it is not a mis-spell, doc retev
	}

	if (que1.empty()) {
		printf("No intersections were found for all words in file\n");
	}
	else {
		for (int i = 0; i<que1.size(); i++) {
			std::cout << que1[i] << std::endl;
		}
	}
	
	return 0;
}

std::string Test::removePuncFromLine(std::string line1) {

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
