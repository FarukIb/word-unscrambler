#include "Trie.h"
#include "TrieNode.h"
#include <string>
#include <fstream>

using namespace std;

TrieNode root;

Trie::Trie()
{
	root.setIsWord(false);
}

Trie::Trie(bool initializeDictionary)
{
	if (initializeDictionary)
		fillTrie();
	root.setIsWord(false);
}

void Trie::addWord(string x)
{
	TrieNode* lastNode = addWordHelper(&root, x[0]);
	for (int i = 1; i < x.size(); i++)
		lastNode = addWordHelper(lastNode, x[i]);		
	lastNode->setIsWord(true);
}

TrieNode* Trie::addWordHelper(TrieNode* rt, char x)
{
	return rt->addChar(x, false);
}

bool Trie::exists(string x)
{
	TrieNode* lastNode = &root;
	for (int i = 0; i < x.size(); i++)
	{
		if (lastNode->isThere(x[i]) == 0)
			return false;
		lastNode = lastNode->isThere(x[i]);
	}
	return true;
}

bool Trie::isWord(string x)
{
	TrieNode* lastNode = &root;
	for (int i = 0; i < x.size(); i++)
	{
		if (lastNode->isThere(x[i]) == 0)
			return false;
		lastNode = lastNode->isThere(x[i]);
	}
	return lastNode->getIsWord();
}

void Trie::fillTrie()
{
	fstream dict("dictionary.txt");
	string wrd;
	while (dict >> wrd)
		if (wrd.size() > 2)
			addWord(wrd);
}
