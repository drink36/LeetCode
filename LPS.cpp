#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {

        string result = "";
        string temp = "";
        int n = s.size();
        int n_result = 0;
        int pos = 0;
        vector<int> data;
        if (n <= 1)
            return s;
        else
        {
            int mirror = -1;
            int Right_edge = -1;
            int temp_pos = 0;
            int right = 1;
            for (int i = 0; i < n; i++)
            {
                temp += '$';
                temp += s[i];
            }
            temp += '$';
            data.resize(temp.size(), 0);
            while (pos < temp.size())
            {
                while ((pos - (right) >= 0) && (pos + (right) < temp.size()))
                {
                    if (temp[pos + right] == temp[pos - right])
                    {
                        right++;
                    }
                    else
                    {
                        break;
                    }
                }
                data[pos] = right - 1;
                Right_edge = pos + data[pos];
                temp_pos = pos;
                pos++;
                right = 1;
                while (pos < Right_edge)
                {
                    mirror = temp_pos - (pos - temp_pos);
                    if (pos + data[mirror] < Right_edge)
                    {

                        data[pos] = data[mirror];
                    }
                    else if (pos + data[mirror] > Right_edge)
                    {
                        data[pos] = Right_edge - pos;
                    }
                    else
                    {
                        right += (Right_edge - pos);
                        break;
                    }
                    pos++;
                }
            }
            n_result = max_element(data.begin(), data.end()) - data.begin();
        }
        result = temp.substr(n_result - data[n_result], data[n_result] * 2 + 1);
        result.erase(remove(result.begin(), result.end(), '$'), result.end());
        return result;
    }
};
int main()
{
    Solution s;
    string s1 = "baabd";
    string s2 = "cbbd";
    string s3 = "ccc";
    cout << s.longestPalindrome(s1) << endl;
    cout << s.longestPalindrome(s2) << endl;
    cout << s.longestPalindrome(s3) << endl;
    return 0;
}