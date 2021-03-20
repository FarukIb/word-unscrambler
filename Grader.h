#ifndef GRADER_H
#define GRADER_H

#include <map>
#include <string>
#include <vector>

using namespace std;

#pragma once
class Grader
{
public:
	Grader();
	void toggleArch();
	void toggleBow();
	vector<pair<string, int> > sortWords(vector<string> words);
private:
	//int cmp(pair<string, int> a, pair<string, int> b);
	int getGrade(string a);
	std::map<char, double> grades;
	vector<pair<string, int> > wordNum;
	bool arch, bow;
};

#endif