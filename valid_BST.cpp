#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool isValidBST(TreeNode *root, TreeNode *min = nullptr, TreeNode *max = nullptr)
    {
        if (root == nullptr)
            return true;
        if ((min == nullptr || root->val > min->val) && (max == nullptr || root->val < max->val))
        {
            return (isValidBST(root->left, min, root) && isValidBST(root->right, root, max));
        }
        return false;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << s.isValidBST(root) << endl;

    return 0;
}