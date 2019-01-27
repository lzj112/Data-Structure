#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode 
{
    int value;
    TreeNode* left;
    TreeNode* right;
};


void show(TreeNode* node);
stack<TreeNode *> treeNodeStack;

//中左右
//前序遍历
void preorderTraversalRecursion(TreeNode *node)
{
    if (node == nullptr) 
    {
        return ;
    }
    
    TreeNode* tmpNode;
    treeNodeStack.push(node);
    while (!treeNodeStack.empty()) 
    {
        tmpNode = treeNodeStack.top();  //访问栈顶元素
        treeNodeStack.pop();

        show(tmpNode);  //访问节点
        
        if (tmpNode->right != nullptr) //先将右节点压栈,这样先出栈访问的是左节点
        {
            treeNodeStack.push(tmpNode->right);
        }
        if (tmpNode->left != nullptr) 
        {
            treeNodeStack.push(tmpNode->left);
        }    
    }
}

//左中右
//中序遍历
void inorderTraversalRecursion(TreeNode *node)
{
    if (node == nullptr) 
    {
        return ;
    }
    
    TreeNode* tmpNode = node;
    while (!treeNodeStack.empty()) 
    {
        if (tmpNode != nullptr)  
        {
            treeNodeStack.push(tmpNode->left);  //如果左节点不为空一直将左节点入栈
            tmpNode = tmpNode->left;
        }
        else    //当左节点为空,访问栈顶元素(中),然后将当前节点设为右节点继续判断
        {
            tmpNode = treeNodeStack.top();
            treeNodeStack.pop();
            show(tmpNode);

            tmpNode = tmpNode->right;    
        }
    }
}

//左右中
//后序遍历
void postorderTraversalRecursion(TreeNode *node)
{
    TreeNode* pre;
    if (node == nullptr) 
    {
        return ;
    }
    treeNodeStack.push(node);

    while (!treeNodeStack.empty()) 
    {
        TreeNode* now = treeNodeStack.top();
        //出栈条件
            //叶子节点
        if ((now->left == nullptr && now->right == nullptr) || 
            //已经遍历过其左或者右子节点
            (now != nullptr && (now->left == pre || now->right == pre))) 
        {
            treeNodeStack.pop();

            show(now);
            pre = now;
        }
        else 
        {
            /*
            因为先将右,左子节点入栈,出栈就是左右,然后这样一直到一个叶子节点访问,将pre
            指向它,这样回溯的时候其父节点的左右子节点指针就会等于pre(访问过子节点),
            让后就访问这个父节点
            */
            if (now->right != nullptr)  
            {
                treeNodeStack.push(now->right);
            }
            if (now->left != nullptr)
            {
                treeNodeStack.push(now->left);
            }
        }
    }
}


//使用队列,每个左右子节点入队,然后
//层次遍历
void levelTraversalRecursion(TreeNode* node) 
{
    if (node == nullptr) 
    {
        return ;
    }

    queue<TreeNode *> q;
    q.push(node);
    TreeNode* tmpNode;
    while (!q.empty()) 
    {
        tmpNode = q.front();
        q.pop();
        show(tmpNode);

        if (tmpNode->left != nullptr) 
        {
            q.push(tmpNode->left);
        }
        if (tmpNode->right != nullptr) 
        {
            q.push(tmpNode->right);
        }
    }
}