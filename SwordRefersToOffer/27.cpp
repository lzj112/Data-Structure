/*
二叉树的镜像
给一颗二叉树,将其变成源二叉树的镜像
*/

#include <iostream>

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
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot->left == nullptr && 
            pRoot->right == nullptr || pRoot == nullptr) 
        {
            return ; 
        }
        swap(pRoot);

        if (pRoot->left != nullptr)
        Mirror(pRoot->left);
        if (pRoot->right != nullptr)
        Mirror(pRoot->right);
    }

    void swap(TreeNode* root) 
    {
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};
/*
碰见子节点就交换,碰到叶子节点返回
*/