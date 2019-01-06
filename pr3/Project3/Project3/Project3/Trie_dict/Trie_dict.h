#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <vector>
#include <iostream>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')


// trie node
struct TrieNode
{
	TrieNode *children[ALPHABET_SIZE];

	// isLeaf is true if the node represents
	// end of a word
	bool isLeaf;
};


class Trie
{
public:
	Trie() { root = new TrieNode(); }
	
	void insert(const char *key);
	bool search(const char *key);
	void remove_all(TrieNode* node);
	void traverse(std::string prefix, TrieNode* node);
	void autoComp(const char *key);

	~Trie() { remove_all(root); }

	TrieNode* root;
};