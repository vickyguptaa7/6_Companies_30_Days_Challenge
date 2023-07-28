int findNodeCnt(Node *root)
{
    if (!root)
        return 0;

    return 1 + findNodeCnt(root->left) + findNodeCnt(root->right);
}

int findNthElement(Node *root, int &K)
{
    if (!root)
        return 0;

    int left = findNthElement(root->left, K);
    if (left)
        return left;
    K--;
    if (K == 0)
        return root->data;
    int right = findNthElement(root->right, K);
    return right;
}

float findMedian(struct Node *root)
{
    int nodeCnt = findNodeCnt(root);
    if (nodeCnt & 1)
    {
        int no = (nodeCnt + 1) / 2;
        return findNthElement(root, no);
    }
    else
    {
        int n1 = nodeCnt / 2, n2 = (nodeCnt + 2) / 2;
        return (findNthElement(root, n1) + findNthElement(root, n2)) / 2.0;
    }
}
