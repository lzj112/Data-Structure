/*
题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）
形成树的一条路径，最长路径的长度为树的深度。
*/
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};

class Solution
{
  public:
    int TreeDepth(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return 0;
        int l = TreeDepth(pRoot->left) + 1;
        int r = TreeDepth(pRoot->right) + 1;

        return max(l, r);
    }
};