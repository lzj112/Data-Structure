#include <queue>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

struct AVLNode 
{
    AVLNode() 
        : val(0), left(nullptr), right(nullptr) 
    {}
    AVLNode(int v)
        : val(v), left(nullptr), right(nullptr)
    {}
    int val;    //data
    // int height;  //当前结点高度
    AVLNode* left;
    AVLNode* right;
};

class AVLTree 
{
public:
    AVLTree() : root(nullptr) 
    {}
    ~AVLTree()
    {}

    //查找某特定值结点
    AVLNode* findNode(int val) 
    {
        return findNodeInTree(root, val);
    }

    //插入结点,t为插入节点
    void insert(int v) 
    {   
        insertNode(&root, v);
    }

    //删除结点,val是待删除结点data
    void delNode(int val) 
    {
        delNodeFromTree(&root, val);
    }
    
    //层次遍历
    void traverse()
    {
        if (root != nullptr) 
        {
            queue<AVLNode *> q;
            q.push(root);
            AVLNode* tmpPtr;
            while (!q.empty()) 
            {
                tmpPtr = q.front();
                q.pop();
                cout << tmpPtr->val << ' ';

                if (tmpPtr->left != nullptr)
                    q.push(tmpPtr->left);
                if (tmpPtr->right != nullptr) 
                    q.push(tmpPtr->right);
            }
            cout << endl;
        }
    }
    

    //求结点所在高度(只有一个根结点时高度为1)
    int getHeight(AVLNode* t) 
    {
        int leftHeight, rightHeight;
        if (t != nullptr) 
        {
            leftHeight = getHeight(t->left);
            rightHeight = getHeight(t->right);

            return (leftHeight > rightHeight) ? 
                (leftHeight + 1) : (rightHeight + 1);
        }
        else 
            return 0;
    }
private:
    //左左情况旋转(t是失衡结点)
    void LL(AVLNode** t) 
    {
        if (t != nullptr)
        {
            AVLNode* tmpPtr = (*t)->left;
            (*t)->left = tmpPtr->right;    //t左子树的右子树作为t的左子树
            tmpPtr->right = *t;
            *t = tmpPtr;
        }
    }
    //右右情况旋转
    void RR(AVLNode** t)
    {
        if (t != nullptr) 
        {
            AVLNode* tmpPtr = (*t)->right;
            (*t)->right = tmpPtr->left;
            tmpPtr->left = *t;
            *t = tmpPtr;
        }
    }
    //左右情况旋转 (t为失衡结点,新节点位于t的左子树的右子树)
    void LR(AVLNode** t) 
    {
        RR(&(*t)->left);
        LL(t);
    }
    //右左情况旋转
    void RL(AVLNode** t) 
    {
        LL(&(*t)->right);
        RR(t);
    }

    //插入结点
    void insertNode(AVLNode** t, int v) 
    {   
        //插入结点,使用二级指针改变父节点左右子树指针指向
        if (*t == nullptr) 
            *t = new AVLNode(v); 
        else if (v < (*t)->val) 
        {
            insertNode(&((*t)->left), v);
            int leftH = getHeight((*t)->left);
            int rightH = getHeight((*t)->right);
            //插入到左子树,肯定是左子树高度更高,判断这时平衡因子是否大于1
            if ((leftH - rightH) > 1) 
            {
                if (v < (*t)->left->val) 
                    LL(t);
                else
                    LR(t);
            }
        }
        else if (v > (*t)->val) 
        {
            insertNode(&((*t)->right), v);
            int leftH = getHeight((*t)->left);
            int rightH = getHeight((*t)->right);
            if ((rightH - leftH) > 1) 
            {
                if (v > (*t)->right->val)
                    RR(t);
                else 
                    RL(t);
            }
        }
        else 
            return ;
    }

    AVLNode* findNodeInTree(AVLNode* node, int val) 
    {
        if (node != nullptr) 
        {
            if (val < node->val)
                return findNodeInTree(node->left, val);
            else if (val > node->val) 
                return findNodeInTree(node->right, val);
            else 
                return node;
        }
        else 
            return nullptr;
    }

    int findMaxKeyInLef(AVLNode* node) 
    {
        if (node == nullptr)
            return 0;
        else if (node->right == nullptr)
            return node->val;
        return findMaxKeyInLef(node->right);
    }
    AVLNode* delNodeFromTree(AVLNode** node, int val) 
    {
        if (node == nullptr) 
            return nullptr;
        else if (val < (*node)->val)
        {
            (*node)->left = delNodeFromTree(&(*node)->left, val);
            //判断是否失衡,删了左子树一个结点,所以判断右子树高度是否过高
            if ((getHeight((*node)->right) - getHeight((*node)->left)) > 1) 
                //右子树的左子树高度比右子树的右子树更高,相当于给右子树的右子树插入了新节点,相当于"右右"情况
                if (getHeight((*node)->right->left) > getHeight((*node)->right->right))
                    RL(node);
                else 
                    RR(node);
            return (*node);
        }
        else if (val > (*node)->val)
        {
            (*node)->right = delNodeFromTree(&(*node)->right, val);
            //判断是否失衡,删了右子树一个结点,所以判断左子树高度是否过高
            if ((getHeight((*node)->left) - getHeight((*node)->right)) > 1) 
                //左子树的左子树高度比右子树的右子树更高,相当于给左子树的左子树插入了新节点,相当于"左左"情况
                if (getHeight((*node)->left->left) > getHeight((*node)->left->right))
                    LL(node);
                else 
                    LR(node);
            return (*node);
        }
        else if (val == (*node)->val)
        {
            //如果是叶子节点
            if ((*node)->left == nullptr && (*node)->right == nullptr) 
            {
                delete (*node);
                (*node) = nullptr;
                return (*node);;
            }
            //如果左子树非空,将右子树续接到父节点
            else if ((*node)->left != nullptr) 
            {
                AVLNode* tmp = (*node)->left;
                delete (*node);
                return tmp;
            }
            //如果右子树非空,将左子树续接到父节点
            else if ((*node)->right != nullptr) 
            {
                AVLNode* tmp = (*node)->right;
                delete (*node);
                return tmp;
            }
            //左右子树皆非空
            else 
            {
                //寻找左子树中最大节点,即左子树中最右节点
                //(也可以寻找右子树中最小节点,即右子树中最左节点)
                int maxVal = findMaxKeyInLef((*node)->left);
                //交换这两个节点
                (*node)->val = maxVal;
                //删除那个用来交换的节点
                (*node)->left = delNodeFromTree(&(*node)->left, maxVal);
                return *node;
            }
        }
    }
    
    AVLNode* root;
};

int main() 
{
    AVLTree tree;
    // vector<int> tmp = {99, 1, 34, 23, 67, 7};
    vector<int> tmp = {99, 1, 34, 56, 23, 67, 78, 9, 45, 684, 35, 678, 234, 89, 90, 24, 672, 1, 1, 4};
    for (auto x : tmp) 
    {
        tree.insert(x);
    }
    tree.traverse();


    AVLNode* p = tree.findNode(672);
    if (p == nullptr)
        cout << "672 is not in the tree" << endl;
    else 
        cout << "succeed in finding " << p->val << endl;

    tree.delNode(672);
    tree.traverse();

    p = tree.findNode(672);
    if (p == nullptr)
        cout << "672 is not in the tree" << endl;
    else 
        cout << "succeed in finding " << p->val << endl;
        
}