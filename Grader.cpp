#include "Grader.h"
#include <math.h>
#include <algorithm>
#define psi pair<string, int>

bool arch, bow;
std::map<char, double> grades;
vector<psi> wordNum;

using namespace std;

Grader::Grader()
{
	arch = false;
	bow = false;

	grades['a'] = 1;
	grades['d'] = 1;
	grades['e'] = 1;
	grades['g'] = 1;
	grades['i'] = 1;
	grades['l'] = 1;
	grades['n'] = 1;
	grades['o'] = 1;
	grades['r'] = 1;
	grades['s'] = 1;
	grades['t'] = 1;
	grades['u'] = 1;

	grades['b'] = 1.25;
	grades['c'] = 1.25;
	grades['f'] = 1.25;
	grades['h'] = 1.25;
	grades['m'] = 1.25;
	grades['p'] = 1.25;

	grades['v'] = 1.5;
	grades['w'] = 1.5;
	grades['y'] = 1.5;

	grades['j'] = 1.75;
	grades['k'] = 1.75;
	grades['q'] = 1.75;

	grades['x'] = 2;
	grades['z'] = 2;
}

void Grader::toggleArch()
{
	if (arch == true)
		arch = false;
	else
		arch = true;
}

void Grader::toggleBow()
{
	if (bow == true)
		bow = false;
	else
		bow = true;
}

int cmp(psi a, psi b)
{
	if (a.second < b.second)
		return 0;
	return 1;
}

int Grader::getGrade(string a)
{
	if (bow)
		grades['x'] = 2.5, grades['y'] = 2.5, grades['z'] = 2.5;
	if (arch)
		grades['x'] = 3, grades['y'] = 3, grades['z'] = 3;

	double x = 0;
	for (int i = 0; i < a.size(); i++)
		x += grades[a[i]];

	return round(x);
}

vector<psi> Grader::sortWords(vector<string> words)
{
	wordNum.clear();

	for (int i = 0; i < words.size(); i++)
		wordNum.push_back(psi(words[i], getGrade(words[i])));

	sort(wordNum.begin(), wordNum.end(), 
		[](psi lhs, psi rhs)
		{
			return lhs.second < rhs.second;
		}
	);

	return wordNum;
}