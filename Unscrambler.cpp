#include "Unscrambler.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, bool> used;
vector<string> words;
Trie trie;
int n;

Unscrambler::Unscrambler()
{
	trie.fillTrie();
}

vector<string> Unscrambler::getWords(string inp)
{
	used.clear();
	words.clear();
	n = inp.size();

	recur("", inp);

	return words;
}

void Unscrambler::recur(string curr, string left)
{
	if (!trie.exists(curr) || curr.size() == n || used[curr])
		return;
	if (trie.isWord(curr))
		words.push_back(curr);

	used[curr] = true;
	for (int i = 0; i < left.size(); i++)
	{
		string currN = curr;
		currN += left[i];
		string neww;
		for (int j = 0; j < left.size(); j++)
		{
			if (j == i)
				continue;
			neww += left[j];
		}
		recur(currN, neww);
	}
}