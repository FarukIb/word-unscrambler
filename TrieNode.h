#ifndef TRIENODE_H
#define TRIENODE_H

#pragma once
#include <map>
#include <string>
#include "TrieNode.h"

using namespace std;

class TrieNode
{
public:
	TrieNode();
	TrieNode(string wor, bool isW);

	bool getIsWord();

	void setIsWord(bool x);

	string getWord();

	TrieNode* isThere(char x);

	TrieNode* addChar(char x, bool isWord);
private:
	map<char, TrieNode> children;
	bool isWord;
	string word;
	int n;
};

#endif TRIENODE_H