/*
Inorder Traversal
*/

#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return vector<int> ();

        vector<int> ret;
        stack<TreeNode *> nodeStack;
        while (!nodeStack.empty() || root != nullptr) 
        {
            if (root != nullptr) 
            {
                nodeStack.push(root);
                root = root->left;
            }
            else 
            {
                root = nodeStack.top();
                nodeStack.pop();
                ret.push_back(root->val);
                root = root->right;
            }
        }
        return ret;
    }
};