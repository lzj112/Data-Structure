/*
给出前序遍历和中序遍历的结果
重构二叉树
*/

#include <iostream>
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
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.empty() || vin.empty()) 
            return nullptr;
        TreeNode* head = new TreeNode(pre[0]);  //前序遍历首元素就是根节点

        int len = static_cast<int> (pre.size());
        int rootVal;
        for (int i = 0; i < len; i++) 
        {
            if (vin[i] == pre[0])   //找到中序遍历中根节点的位置,记录下标
            {
                rootVal = i;
                break;
            }
        }

        vector<int> left_pre, left_vin, right_pre, right_vin;
        //保存左子树的前序和中序遍历结果
        for (int i = 0; i < rootVal; i++) 
        {
            left_pre.push_back(pre[i + 1]);
            left_vin.push_back(vin[i]);
        }
        //保存右子树前序中序遍历结果
        for (int i = rootVal + 1; i < len; i++) 
        {
            right_pre.push_back(pre[i]);
            right_vin.push_back(pre[i]);
        }

        //递归构建左右子树
        head->left = reConstructBinaryTree(left_pre, left_vin);
        head->right = reConstructBinaryTree(right_pre, right_vin);

        return head;
    }
};
