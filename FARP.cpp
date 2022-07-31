#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> result;
        for (int i = 0; i < words.size(); i++)
        {
            vector<int> wordnum(26, 100);
            vector<bool> used(26, false);
            for (int j = 0; j < words[i].size(); j++)
            {
                int temp = words[i][j] - pattern[i];
                if ((wordnum[pattern[j] - 'a']) != 100)
                {
                    if (temp != wordnum[pattern[j] - 'a'])
                        break;
                }
                else
                {
                    if (used[words[i][j] - 'a'])
                        break;
                    used[words[i][j] - 'a'] = true;
                    wordnum[pattern[j] - 'a'] = temp;
                }
                if (j == words[i].size() - 1)
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};
int main()
{
    
}