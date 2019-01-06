#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>

class DocRet {

public:
	std::unordered_map<std::string, std::vector<std::string>> mymap;
	std::vector<std::string> fileList;
	
	void createInvertIndex();
	void createFileList();
	std::string removePuncFromLine(std::string);
};