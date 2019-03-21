/*
二叉搜索树中第K大结点
给定一颗二叉搜索树,请找出其中第K小结点
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
    TreeNode* KthNode(TreeNode *pRoot, int k)
    {
        stack<TreeNode *> st;
        int count = 0;
        if (pRoot == nullptr || k <= 0)
            return nullptr;
        while (!st.empty() || pRoot != nullptr) 
        {
            if (pRoot != nullptr) 
            {
                st.push(pRoot);
                pRoot = pRoot->left;
            }
            else 
            {
                pRoot = st.top();
                st.pop();
                if (++count == k)
                {
                    cout << pRoot->val << endl;
                    break;
                }
                pRoot = pRoot->right;
            }
        }
        return nullptr;
    }
};

