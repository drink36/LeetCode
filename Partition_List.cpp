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
    void testPrint(ListNode *head)
    {
        ListNode *p = head;
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *first = (head->val < x) ? head : nullptr;
        ListNode *back = nullptr;
        ListNode *backfirst = nullptr;
        ListNode *pNode = nullptr;
        while (head)
        {
            if (head->val < x)
            {
                if (!first)
                {
                    first = head;
                }
                pNode = head;
                head = head->next;
            }
            else
            {
                if (!back)
                {
                    backfirst = head;
                    back = backfirst;
                }
                else
                {
                    back->next = head;
                    back = back->next;
                }
                if (pNode)
                {
                    head = head->next;
                    pNode->next = head;
                    back->next = nullptr;
                }
                else
                {
                    head = head->next;
                    back->next = nullptr;
                }
            }
        }
        pNode->next = backfirst;
        return first;
    }
};
int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    s.partition(head, 3);
    return 0;
}