/*
对称的二叉树
判断一颗二叉树是不是对称的,如果一颗二叉树和他的镜像一样
则他是对称的
*/
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
    bool isSame(TreeNode* p1, TreeNode* p2) 
    {
        if (p1 == nullptr && p2 == nullptr) 
        {
            return true;    //遍历到叶子
        }
        if (p1 == nullptr || p2 == nullptr) 
        {
            return false;
        }
        if (p1->val != p2->val) 
        {
            return false;   //倘若相等继续遍历
        }
        return isSame(p1->left, p2->right) && isSame(p1->right, p2->left);
    }
    bool isSymmetrical(TreeNode *pRoot)
    {  
       
        return isSame(pRoot, pRoot);
    }
};