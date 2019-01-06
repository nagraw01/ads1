
#include "Spell_Check.h"


void SpellCheck::substitution(std::string key) {
	std::string temp = key;

	for (int i = 0; i<key.length(); i++) {
		for (char j = 'a'; j <= 'z'; j++) {

			std::stringstream ss;
			std::string s;

			ss << j;
			ss >> s;

			key.replace(i, 1, s);

			words.push(key);
		}
		key = temp;
	}
}


void SpellCheck::insertion(std::string key) {
	std::string temp = key;

	for (int i = 0; i <= key.length(); i++) {
		for (char j = 'a'; j <= 'z'; j++) {
			std::stringstream ss;
			std::string s;

			ss << j;
			ss >> s;

			key.insert(i, s);

			words.push(key);
			key = temp;
		}

	}
}

void SpellCheck::deletion(std::string key) {
	std::string temp = key;
	for (int i = 0; i<key.length(); i++) {
		key.erase(key.begin() + i);
		words.push(key);
		key = temp;
	}

}

char* SpellCheck::handle1(std::string s) {
	char* c1 = &s[0];
	if (isupper(c1[0])) c1[0] = tolower(c1[0]);
	return c1;
}

void SpellCheck::misSpell(std::string sub) {
	substitution(sub);
	deletion(sub);
	insertion(sub);
}