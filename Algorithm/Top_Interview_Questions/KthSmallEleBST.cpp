/*
给定一个二叉搜索树，写一个函数kthminimum来找到其中的第k个最小的元素。
注意:
你可以假设k总是有效的，1≤k≤BST的总元素。
*/
#include <stack>
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
    
    int kthSmallest(TreeNode *root, int k)
    {
        if (root == nullptr)
            return 0;
        int count = 0;
        stack<TreeNode *> st;
        while (!st.empty() || root != nullptr) 
        {
            if (root != nullptr) 
            {
                st.push(root);
                root = root->left;
            }
            else 
            {
                ++count;
                root = st.top();
                st.pop();
                if (count == k)
                    return root->val;
                root = root->right;
            }
        }
        return 0;
    }
};