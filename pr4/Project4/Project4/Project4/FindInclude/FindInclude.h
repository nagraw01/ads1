#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

class FindInclude {

public:
	std::unordered_map<std::string, std::vector<std::string>> mymap;

	FindInclude() {}
	void readFile(std::string, std::string);
	void display_map();
	void set_map(std::string s);
};