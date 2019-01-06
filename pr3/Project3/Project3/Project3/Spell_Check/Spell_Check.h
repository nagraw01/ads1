#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

class SpellCheck {
public:
	SpellCheck() {}
	
	std::vector<std::string> suggestions;
	std::queue<std::string> words;

	void substitution(std::string);
	void deletion(std::string);
	void insertion(std::string);
	char* handle1(std::string);
	void misSpell(std::string);

	~SpellCheck() {}
};