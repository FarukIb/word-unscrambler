#ifndef UNSCRAMBLER_H
#define UNSCRAMBLER_H

#include <vector>
#include <string>
#include "Trie.h"

using namespace std;

#pragma once
class Unscrambler
{
public:
	Unscrambler();
	vector<string> getWords(string inp);
private:
	map<string, bool> hash;
	Trie trie;
	void recur(string curr, string left);
	vector<string> words;
	map<string, bool> used;
};

#endif UNSCRAMBLER_H