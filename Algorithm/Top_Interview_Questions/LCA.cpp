/*
给定一棵二叉树，找出树中两个给定节点的最低公共祖先(LCA)。
根据Wikipedia对LCA的定义:“在两个节点p和q之间定义的最低公共祖先是T
中同时具有p和q作为后代的最低节点(在这里，我们允许一个节点作为其自身的后代)。”
给出如下二叉树:root = [3,5,1,6,2,0,8,null,null,7,4]
示例1:
输入:根=(3、5、1、6 2 0 8,空,空,7日,4],p = 5, q = 1
输出:3
说明:节点5和节点1的LCA为3。
示例2:
输入:根=(3、5、1、6 2 0 8,空,空,7日,4],p = 5, q = 4
输出:5
说明:节点5和节点4的LCA为5，因为根据LCA定义，节点可以是自身的后代。
注意:
所有节点的值都是惟一的。
p和q是不同的，两个值都存在于二叉树中。
*/

//最近公共祖先问题

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || q == nullptr || p == nullptr)
            return root;
        if (root == p || root == q) 
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);    //递归搜索左子树
        TreeNode* right = lowestCommonAncestor(root->right, p, q);  //递归搜索右子树

        if (left == nullptr)    //说明p q都在右子树
            return right;
        else if (right == nullptr)  //说明p q都在左子树
            return left;
        else                //说明p q分别在左右子树,根节点就是最近公共祖先
            return root;
    }
};