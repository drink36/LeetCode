#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        bool positive = true;
        int max = 214748364;
        int result = 0;
        if (x < 0)
        {
            positive = false;
            if (x == INT_MIN)
            {
                return 0;
            }
            else
            {
                x = -x;
            }
        }

        while (x > 0)
        {
            if (result > max || (result == max && (x % 10 > 7 || (x % 10 == 7 && positive == false))))
                return 0;
            result = result * 10 + x % 10;
            x = x / 10;
        }
        return positive ? result : -result;
    }
};
int main()
{
    Solution s;
    cout << s.reverse(INT_MAX) << endl;
    return 0;
}