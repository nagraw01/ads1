#pragma once

#include "../dirent.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

class FindPack {
public:
	std::vector<std::string> pack;

	FindPack() {}
	void readPackages(std::string);
	//void readPackages();
	void display_pack();
};

