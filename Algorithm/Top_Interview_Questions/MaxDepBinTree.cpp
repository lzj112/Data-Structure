/*
给定一个二叉树，求它的最大深度。
最大深度是从根节点到最远叶节点的最长路径上的节点数。
注意:叶子是没有子节点的节点。
例子:
给定二叉树[3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7
返回深度= 3。
*/

/**
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 *
 */

#include <iostream>
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftLen = maxDepth(root->left) + 1;
        int rightLen = maxDepth(root->right) + 1;
        return max(leftLen, rightLen);
    }
};

//非递归的做法: 层次遍历,每遍历一层count++