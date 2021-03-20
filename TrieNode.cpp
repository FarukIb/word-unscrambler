#include "TrieNode.h"
#include <string>
#include <map>

using namespace std;

string word;
bool isWord;
map<char, TrieNode> children;

TrieNode::TrieNode()
{
	isWord = false;
	word = "";
}

TrieNode::TrieNode(string wor, bool isW)
{
	word = wor;
	isWord = isW;	
}

bool TrieNode::getIsWord()
{
	return isWord;
}

void TrieNode::setIsWord(bool x)
{
	isWord = x;
}

string TrieNode::getWord()
{
	return word;
}

TrieNode* TrieNode::isThere(char x)
{
	if (children.find(x) == children.end())
		return 0;
	return &children[x];
}

TrieNode* TrieNode::addChar(char x, bool isWord)
{
	if (children.find(x) == children.end())
	{
		TrieNode toAdd(word + x, isWord);
		children[x] = toAdd;
	}
	else
	{
		if (children[x].getIsWord() == false)
			children[x].setIsWord(isWord);
	}

	return &(children[x]);
}
