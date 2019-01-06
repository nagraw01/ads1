
#include "Trie_dict.h"

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void Trie::insert(const char *key)
{
	int level;
	int length = strlen(key);
	int index;

	TrieNode *pCrawl = root;

	for (level = 0; level < length; level++)
	{
		/*char c;
		if (isupper(key[level])) c = tolower(key[level]);
		else c = key[level];*/
		index = CHAR_TO_INDEX(key[level]);
		if (!pCrawl->children[index])
			pCrawl->children[index] = new TrieNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isLeaf = true;
}

// Returns true if key presents in trie, else false
bool Trie::search(const char *key)
{
	int level;
	int length = strlen(key);
	int index;
	TrieNode *pCrawl = root;

	for (level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);

		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isLeaf);
}

//function for auto-complete
void Trie::autoComp(const char *key)
{
	int level;
	std::vector<std::string> vec;
	int length = strlen(key);
	int index;
	TrieNode *pCrawl = root;

	for (level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);

		if (!pCrawl->children[index]) {
			std::cout << "no words in dictionery for this prefix";
			return;
		}

		pCrawl = pCrawl->children[index];
	}

	if (pCrawl != NULL && pCrawl->isLeaf) {
		vec.push_back(key);
	}
	traverse(key, pCrawl);
}

//void Trie::dfs(TrieNode* node)
//{
//	int level;
//
//	TrieNode *pCrawl = node;
//
//	for (level = 0; level < 26; level++)
//	{
//
//		if (!pCrawl->children[level] || pCrawl->isLeaf)
//			continue;
//		
//		pCrawl = pCrawl->children[level];
//		dfs(pCrawl);
//	}
//
//}

void Trie::traverse(std::string prefix, TrieNode* node) {
	if (node->isLeaf) {
		//printf("%s\n", prefix);
		char* c2 = &prefix[0];
		std::cout << "autocorrect options.... " << c2 << std::endl;
	}

	for (char index = 0; index < ALPHABET_SIZE; ++index) {
		char next = 'a' + index;
		TrieNode* pChild = node->children[index];
		if (pChild) {
			prefix.push_back(next);
			traverse(prefix, pChild);
			prefix.pop_back();
		}
	}
}

///to delete the trie and empty the memory at the end
void Trie::remove_all(TrieNode* node)
{
	if (!node)
	{
		return;
	}
	
	for (int i = 0; i<ALPHABET_SIZE; i++) { remove_all(node->children[i]); }


	delete node;
}