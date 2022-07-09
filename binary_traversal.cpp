#include <iostream>
#include <queue>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<int> q_level;
        queue<TreeNode *> q;
        q.push(root);
        q_level.push(0);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            int temp_level = q_level.front();
            q.pop();
            q_level.pop();
            if (temp_level == result.size())
            {
                vector<int> temp_vector;
                temp_vector.push_back(temp->val);
                result.push_back(temp_vector);
            }
            else
            {
                result[temp_level].push_back(temp->val);
            }
            if (temp->left != nullptr)
            {
                q.push(temp->left);
                q_level.push(temp_level + 1);
            }
            if (temp->right != nullptr)
            {
                q.push(temp->right);
                q_level.push(temp_level + 1);
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    s.levelOrder(root);
    return 0;
}