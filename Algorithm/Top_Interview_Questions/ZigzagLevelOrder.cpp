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
        
    }
    
};