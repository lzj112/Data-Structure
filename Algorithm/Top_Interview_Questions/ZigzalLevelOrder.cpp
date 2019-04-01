/*
给定一棵二叉树，返回其节点值的之字形顺序遍历。(即，从左到右，然后从右到左的下一层和之间的交替)。
例如:
给定二叉树[3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        stack<TreeNode *> s1, s2;
        s1.push(root);
        TreeNode *cur;
        vector<vector<int>> res;
        vector<int> out;

        while (!s1.empty() || !s2.empty())
        {
            while (!s1.empty())
            {
                cur = s1.top();
                s1.pop();
                out.push_back(cur->val);
                if (cur->left != nullptr)
                    s2.push(cur->left);
                if (cur->right != nullptr)
                    s2.push(cur->right);
            }
            if (!out.empty())
                res.push_back(out);
            out.clear();

            while (!s2.empty())
            {
                cur = s2.top();
                s2.pop();
                out.push_back(cur->val);

                if (cur->right != nullptr)
                    s1.push(cur->right);
                if (cur->left != nullptr)
                    s1.push(cur->left);
            }

            if (!out.empty())
                res.push_back(out);
            out.clear();
        }
        return res;
    }
};