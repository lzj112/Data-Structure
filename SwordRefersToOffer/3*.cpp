/*
之字形打印二叉树
*/

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
  public:
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        if (pRoot == nullptr) 
            return {};
        vector<vector<int> > ret;
        stack<TreeNode *> st1, st2;
        st1.push(pRoot);
        vector<int> tmp;
        while (!st1.empty() || !st2.empty()) 
        {
            while (!st1.empty()) 
            {
                TreeNode* node = st1.top();
                st1.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr)
                    st2.push(node->left);
                if (node->right != nullptr)
                    st2.push(node->right);
            }
            if (!tmp.empty())
                ret.push_back(tmp);
            tmp.clear();
            while (!st2.empty()) 
            {
                TreeNode* node = st2.top();
                st2.pop();
                tmp.push_back(node->val);
                if (node->right != nullptr)
                    st1.push(node->right);
                if (node->left != nullptr)
                    st1.push(node->left);
            }
            if (!tmp.empty())
                ret.push_back(tmp);
            tmp.clear();
        }
        return ret;
    }
};