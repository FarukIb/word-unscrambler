#ifndef TRIE_H
#define TRIE_H

#pragma once
#include "TrieNode.h"
#include <map>
#include <string>

using namespace std;

class Trie
{
public:
	Trie();

	Trie(bool test);

	void addWord(string x);

	TrieNode* addWordHelper(TrieNode* rt, char x);

	bool exists(string x);

	bool isWord(string x);

	void fillTrie();
private:
	TrieNode root;
};

#endif