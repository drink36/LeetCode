#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int s = lists.size();
        ListNode *result = nullptr;
        if (s == 1)
            return lists[0];
        else if (s == 0)
            return result;
        for (int i = 0; i < s - 1; i++)
        {
            ListNode *temp = nullptr;
            ListNode *temp1 = nullptr;
            if (lists[i] != nullptr && lists[i + 1] != nullptr)
            {
                if (lists[i]->val < lists[i + 1]->val)
                {
                    temp1 = lists[i];
                    lists[i] = lists[i]->next;
                }
                else
                {
                    temp1 = lists[i + 1];
                    lists[i + 1] = lists[i + 1]->next;
                }
            }
            else if (lists[i] != nullptr)
            {
                lists[i + 1] = lists[i];
                continue;
            }
            else if (lists[i + 1] != nullptr)
            {
                continue;
            }
            else
            {
                i++;
                continue;
            }
            temp = temp1;
            while (lists[i] != nullptr && lists[i + 1] != nullptr)
            {
                if (lists[i]->val < lists[i + 1]->val)
                {
                    temp1->next = lists[i];
                    lists[i] = lists[i]->next;
                    temp1 = temp1->next;
                }
                else
                {
                    temp1->next = lists[i + 1];
                    lists[i + 1] = lists[i + 1]->next;
                    temp1 = temp1->next;
                }
            }
            if (lists[i] != nullptr)
                temp1->next = lists[i];
            else
                temp1->next = lists[i + 1];
            lists[i + 1] = temp;
        }
        return lists.back();
    }
};
int main()
{
    return 0;
}