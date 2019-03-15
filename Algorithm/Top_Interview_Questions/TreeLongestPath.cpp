
struct TreeNode
{
    int value;
    TreeNode *pLeft;
    TreeNode *pRight;
};

/*
求树的最长路径
给定一个二叉树，任意两个节点之间
必然是有一条路径相通的，假定父节点和它的孩子节点的距离为单位1
求二叉树中相距最远的两个节点间的路径长度
*/

//max是最长路径,初始调用传其指针
int MaxDistance(TreeNode *root, int *max)
{
    if (root->pLeft == nullptr && root->pRight == nullptr)
    {
        return 0;
    }

    int left_len = 0, right_len = 0;
    if (root->pLeft != nullptr)
    {
        left_len = MaxDistance(root->pLeft, max) + 1;
    }
    if (root->pRight != nullptr)
    {
        right_len = MaxDistance(root->pRight, max) + 1;
    }

    int sum = left_len + right_len + 2; //两个叶子结点的距离
    *max = (*max > sum) ? *max : sum;

    //返回左右子树中较大长度
    return (left_len > right_len) ? left_len : right_len;
}

/*
最大路径和问题

下面再看最大路径和问题（路径和为两个节点之间所在路径上的节点权值之和）。
这个问题和上题非常相似，只不过是把单位距离换成了节点上的权值而已。
*/

//跟上面差不多,maxsum初始调用时传其指针
int MaxPathSum(TreeNode *root, int *maxsum)
{
    int val = root->value;
    if (root->pLeft == nullptr && root->pRight == nullptr)
    {
        return val;
    }

    int left = 0, right = 0;
    if (root->pLeft != nullptr)
    {
        left = MaxPathSum(root->pLeft, maxsum) + val;
    }
    if (root->pRight != nullptr)
    {
        right = MaxPathSum(root->pRight, maxsum) + val;
    }

    //最大和肯定是左右子树的两个叶子结点之间
    //减去加了两遍的中间父结点
    int sum = left + right - val;
    *maxsum = (*maxsum > sum) ? *maxsum : sum;

    //返回左右子树的结点权值和
    return (left > right) ? left : right;
}
