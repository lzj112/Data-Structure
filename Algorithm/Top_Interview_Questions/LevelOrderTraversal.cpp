/*
给定一个二叉树，返回其节点值的层次顺序遍历。(从左到右，一层一层地)。
例如:
给定二叉树[3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7

返回其层序遍历为:
[
  [3],
  [9,20],
  [15,7]
]
*/

#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/*
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int> > res;
        levelorder(root, 0, res);
        return res;
    }
    void levelorder(TreeNode *node, int level, vector<vector<int> > &res)
    {
        if (!node)
            return;
        if (res.size() == level)
            res.push_back({});
        res[level].push_back(node->val);
        if (node->left)
            levelorder(node->left, level + 1, res);
        if (node->right)
            levelorder(node->right, level + 1, res);
    }
};
*/
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int> > res;
        queue<TreeNode *> q{{root}};
        while (!q.empty())
        {
            vector<int> oneLevel;
            for (int i = q.size(); i > 0; --i)  //每次确定树的每一层的结点数,然后添加新的子结点
            {
                TreeNode *t = q.front();
                q.pop();
                oneLevel.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            res.push_back(oneLevel);
        }
        return res;
    }
};