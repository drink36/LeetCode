#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0 || target < nums[0] || target > nums.back())
        {
            return vector<int>{-1, -1};
        }
        int f = 0, l = nums.size() - 1;
        int mid = (f + l) / 2;
        int temp = -1;
        bool flag = false, flag2 = false;
        vector<int> result(2);
        while (f <= l)
        {
            if (target == nums[mid])
            {
                temp = mid;
                break;
            }
            else if (target > nums[mid])
            {
                f = mid + 1;
                mid = (f + l) / 2;
            }
            else if (target < nums[mid])
            {
                l = mid - 1;
                mid = (f + l) / 2;
            }
        }
        if (temp == -1)
            return vector<int>{-1, -1};
        while (1)
        {
            if (nums[f] == target && !flag)
                flag = true;
            else if (nums[f] == target)
                f--;
            else if (flag)
            {
                result[0] = ++f;
                break;
            }
            else
                f++;
        }
        while (1)
        {
            if (nums[l] == target && !flag2)
                flag2 = true;
            else if (nums[l] == target)
                l++;
            else if (flag2)
            {
                result[1] = --l;
                break;
            }
            else
                l--;
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution s;
    vector<int> result = s.searchRange(nums, 6);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}