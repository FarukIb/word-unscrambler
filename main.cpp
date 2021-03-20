#include <iostream>
#include <fstream>
#include <string>
#include "Grader.h"
#include "Trie.h"
#include "Unscrambler.h"

using namespace std;

map<string, bool> dict2;
int main()
{
    cout << "Loading..." << endl;
    Unscrambler unscrambler;

    while (1)
    {
        string inp;
        cout << "Enter letters to unscramble: ";
        cin >> inp;
        
        Grader grader;

        string bow;
        cout << "Bow of Zyx(y/n): ";
        cin >> bow;
        if (bow == "y")
            grader.toggleBow();
        else
        {
            cout << "Bow of Xyzzy(y/n): ";
            cin >> bow;
            if (bow == "y")
                grader.toggleBow();
        }

        vector<string> x = unscrambler.getWords(inp);
        vector<pair<string, int> > sorted = grader.sortWords(x);


        for (pair<string, int> i : sorted)
            cout << i.first << " " << i.second << endl;
        cout << endl;
    }
}
