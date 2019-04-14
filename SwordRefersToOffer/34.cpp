/*
在二叉树中查找有没有一条路径的节点和为给定值
*/

#include <vector>
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
    vector<vector<int> > FindPath(TreeNode *root, int expectNumber)
    {
        if (root == nullptr)
            return {};
        vector<vector<int> > ret;
        vector<int> t;
        func(root, expectNumber, 0, ret, t);
        return ret;
    }

    void func(TreeNode* node, 
              int k, 
              int sum,
              vector<vector<int> >& ret, 
              vector<int> t) 
    {
        sum += node->val;
        if (node->left == nullptr &&
            node->right == nullptr && 
            sum == k) 
        {
            t.push_back(node->val);
            ret.push_back(t);
            return ;
        }
        if (node->left != nullptr)
        {
            t.push_back(node->val);
            func(node->left, k, sum, ret, t);
            t.erase(t.end() - 1);
        }
        if (node->right != nullptr) 
        {
            t.push_back(node->val);
            func(node->right, k, sum, ret, t);
            t.erase(t.end() - 1);
        }
    }
};