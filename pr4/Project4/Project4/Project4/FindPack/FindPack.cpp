
#include "FindPack.h"


using namespace std;

void FindPack::readPackages(string s)
{

	std::string PATH = s;

	DIR *dir = opendir(PATH);

	struct dirent *entry = readdir(dir);// reading the directory

	while (entry != NULL)// for each content of directory
	{
		if (entry->d_type == DT_DIR) {// checking if it is a folder

			std::string pathIN;
			string dir_name(entry->d_name);// dir_name is the variable for each content of directory

			pathIN = PATH + dir_name;

			DIR *dirIN = opendir(pathIN);
			int hncpp = 1;

			struct dirent *entryIN = readdir(dirIN);
			while (entryIN != NULL && hncpp != 3) {//for each content of package

					string file_name(entryIN->d_name);

					if (file_name.compare(dir_name + ".h") == 0) {//check if it has a header file
						++hncpp;
					}

					if (file_name.compare(dir_name + ".cpp") == 0) {//check if it has a cpp file
						++hncpp;
					}

					entryIN = readdir(dirIN);
			}
			closedir(dirIN);

			if (hncpp == 3) {// as stated in the problem...only considered a package if both
			             //header and cpp files are there
				pack.push_back(entry->d_name);
			}
		}
		entry = readdir(dir);
	}
		//displayg the packages
		display_pack();
	closedir(dir);
}

void FindPack::display_pack() {
	for (string k : pack) {
		cout << k << endl;
	}
}