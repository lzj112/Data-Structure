/*
给定一颗二叉树和其中的一个节点,找出其中序遍历的下一个节点
树中的节点除了有两个分别指向左右子节点的指针, 还有一个指向父节点的指针
*/

struct BinaryTreeNode 
{
    int x;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode) 
{
    if (pNode == nullptr) 
    {
        return nullptr;
    }

    BinaryTreeNode* pNext = nullptr;
    /*
    该节点右子树不为空,即中序遍历下一个访问节点节就是其右子树的最左子树节点
    */
    if (pNode->m_pRight != nullptr) 
    {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while (pRight->m_pLeft != nullptr)  //寻找其右子树的最左子树
        {
            pRight = pRight->m_pLeft;
        }
        pNext = pRight;
    }
    /*
    如果该节点没有右子树
    */
    else if (pNode->m_pParent != nullptr) 
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        /*
        如果该节点是其父节点的右子节点
        */
        while (pParent != nullptr && pCurrent == pParent->m_pRight) 
        {
            /*
            寻找一个是其父节点的左子节点的节点,它的父节点是下一个要访问的节点
            */
            pCurrent = pParent; 
            pParent = pParent->m_pParent;
        }
        /*
        如果是其父结点的左子节点,那下一个访问的就是其父节点
        */
        pNext = pParent;
    }

    /*
    根节点的话不符合上面的情况,他的下一个访问节点是nullptr
    */
    return pNext;
}
