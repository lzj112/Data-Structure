
#include <iostream>
using namespace std;

struct BSTNode 
{
    BSTNode(int t) : key(t), left(nullptr), right(nullptr)
    {}
    int key;
    BSTNode* left;
    BSTNode* right;
};


class BSTree
{
public:
    BSTree() : root_(nullptr) {}
    ~BSTree() { release(root_); }
    BSTNode* root() { return root_; }
    BSTNode* insert(int key, BSTNode* node);
    BSTNode* search(int key, BSTNode* node);
    int findMaxKeyInLef(BSTNode* node);
    BSTNode* delNode(int key, BSTNode* node);
    bool isBST(BSTNode* node);
    void show(BSTNode* node);

    BSTNode* root_;

private:
    void release(BSTNode* node) noexcept;
};

void BSTree::release(BSTNode* node) noexcept 
{
    if (node == nullptr) 
        return ;
    if (node->left != nullptr) 
        release(node->left);
    if (node->right != nullptr) 
        release(node->right);
    delete node;
    node = nullptr;
}

BSTNode* BSTree::insert(int key, BSTNode* node) 
{
    //新插入节点总是叶子节点
    if (node == nullptr) 
    {
        node = new BSTNode(key);
        if (root_ == nullptr)
            root_ = node;
        return node; 
    }
    else 
    {
        if (key > node->key)
            node->right = insert(key, node->right);
        else 
           node->left = insert(key, node->left);
        return node;
    }
}

BSTNode* BSTree::search(int key, BSTNode* node) 
{
    if (node == nullptr)
        return node;
    if (key < node->key) 
        return search(key, node->left);
    else if (key > node->key) 
        return search(key, node->right);
    else if (key == node->key)
        return node;
}

int BSTree::findMaxKeyInLef(BSTNode* node) 
{
    if (node == nullptr)
        return 0;
    else if (node->right == nullptr)
        return node->key;
    return findMaxKeyInLef(node->right);
}
BSTNode* BSTree::delNode(int key, BSTNode* node) 
{
    if (node == nullptr) 
        return nullptr;
    else if (key < node->key)
    {
        node->left = delNode(key, node->left);
        return node;
    }
    else if (key > node->key)
    {
        node->right = delNode(key, node->right);
        return node;
    }
    else if (key == node->key)
    {
        //如果是叶子节点
        if (node->left == nullptr && node->right == nullptr) 
        {
            delete node;
            node = nullptr;
            return node;;
        }
        //如果左子树非空,将右子树续接到父节点
        else if (node->left != nullptr) 
        {
            BSTNode* tmp = node->left;
            delete node;
            return tmp;
        }
        //如果右子树非空,将左子树续接到父节点
        else if (node->right != nullptr) 
        {
            BSTNode* tmp = node->right;
            delete node;
            return tmp;
        }
        //左右子树皆非空
        else 
        {
            //寻找左子树中最大节点,即左子树中最右节点
            //(也可以寻找右子树中最小节点,即右子树中最左节点)
            int maxVal = findMaxKeyInLef(node->left);
            //交换这两个节点
            node->key = maxVal;
            //删除那个用来交换的节点
            node->left = delNode(maxVal, node->left);
            return node;
        }
    }
}

void BSTree::show(BSTNode* node) 
{
    if (node == nullptr)
        return ;
    if (node->left != nullptr)
        show(node->left);
    cout << node->key << endl;
    if (node->right != nullptr)
        show(node->right);
}

bool BSTree::isBST(BSTNode* node) 
{
    static BSTNode *prev = NULL;  
    // 中序遍历这棵树，并保存前驱节点至prev中  
    if (node != nullptr) 
    {  
         if (isBST(node->left) == false)  
              return false;  
         //当前节点小于前驱结点,这棵树就不是BST 
         if (prev != NULL && node->key <= prev->key)  
              return false;  
         prev = node;  
         //右子树  
         return isBST(node->right);  
    }  
  
    return true;  
}

int main() 
{
    BSTree bst;
    bst.insert(10, bst.root());
    bst.insert(12, bst.root());
    bst.insert(45, bst.root());
    bst.insert(5, bst.root());
    bst.insert(8, bst.root());
    bst.insert(9, bst.root());
    bst.insert(20, bst.root());

    bst.show(bst.root());

    BSTNode* node = bst.search(20, bst.root());
    cout << "搜索= " << node->key << endl;

    bst.delNode(20, bst.root());
    bst.show(bst.root());

    cout << bst.isBST(bst.root()) << endl;
}