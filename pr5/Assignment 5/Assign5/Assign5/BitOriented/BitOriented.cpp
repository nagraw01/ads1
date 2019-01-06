#pragma once

#include <iostream>
#include <string>
#include <vector>

class Bitoriented {

public:
	void shiftAnd(std::string pattern, std::string text) {
		
		int state = 0;
		int matchBit = 1;
		for (size_t i = 1; i < pattern.length(); ++i) {
			matchBit <<= 1;
		}
		std::vector<int> charactersInP;
		for (int i = 0; i <= 255; ++i) {
			charactersInP.push_back(0);
		}
		for (size_t i = 0, j = 1; i < pattern.length(); ++i, j <<= 1) {
			charactersInP[pattern[i]] |= j;
		}
		
		for (int i = 0; i < text.length(); ++i) {
			state = ((state << 1) | 1) & charactersInP[text[i]];
			if ((matchBit & state) != 0) {
				
				std::cout << "Pattern found at: " << i - (int)pattern.length() + 1;
				std::cout << std::endl;;
			}
		}
	}
};

