#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
    class Trie
    {
        vector<char *> children;

    public:
        Trie()
        {
            children.resize(26, nullptr);
        }
        void insert(string s)
        {
        }
    };

public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
    }
};