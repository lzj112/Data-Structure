/*
树的子结构
输入两颗二叉树, 判断树 B 是不是 树 A 的子结构
*/

#include <iostream>
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
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        bool res = false;
        if (pRoot2 == nullptr || pRoot1 == nullptr) 
        {
            return false;
        }

        //该节点值一样,作为根节点
        if (pRoot1->val == pRoot2->val)
        {
            res = doseTree1HaveTree2(pRoot1, pRoot2);     //以这个节点为根节点往下找
        }
        if (res == false) //没找到去他的左孩子
        {
            res = HasSubtree(pRoot1->left, pRoot2);
        }
        if (res == false) //还找不到,去右孩子
        {
            res = HasSubtree(pRoot1->right, pRoot2);
        }
        return res;
    }
    
    bool doseTree1HaveTree2(TreeNode* node1, TreeNode* node2) 
    {
        //找完了都能对应上
        if (node2 == nullptr) 
        {
            return true;
        }
        //tree2还没找完,tree1已经完了
        if (node1 == nullptr) 
        {
            return false;
        }
        if (node1->val != node2->val) 
        {
            return false;
        }

        return doseTree1HaveTree2(node1->left, node2->left) && 
                doseTree1HaveTree2(node1->right, node2->right);
    }
};