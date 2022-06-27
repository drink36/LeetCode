#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int result = 0;
        int pos = 0;
        bool flag = true;
        bool negative = false;
        while ((s[pos] == ' ' || (s[pos] >= '0' && s[pos] <= '9') || (flag && (s[pos] == '-' || s[pos] == '+'))) && pos < s.size())
        {
            if (s[pos] == '-' || s[pos] == '+')
            {
                flag = false;
                negative = (s[pos] == '-') ? true : false;
                pos++;
                continue;
            }
            if (s[pos] >= '0' && s[pos] <= '9')
            {
                flag = false;
                if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && (s[pos] > '7' || (s[pos] == '7' && !negative))))
                    return negative ? INT_MIN : INT_MAX;
                result = result * 10 + (s[pos] - '0');
            }
            pos++;
        }
        return negative ? -result : result;
    }
};
int main()
{
    Solution s;
    cout << s.myAtoi("-2147483648 asdasf") << endl;
    return 0;
}