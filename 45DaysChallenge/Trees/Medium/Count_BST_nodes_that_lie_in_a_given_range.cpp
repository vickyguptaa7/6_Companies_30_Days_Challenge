class Solution
{
public:
    int getCount(Node *root, int l, int h)
    {
        if (!root)
            return 0;

        bool isInBetween = true;
        if (root->data < l || root->data > h)
            isInBetween = false;

        return getCount(root->left, l, h) + getCount(root->right, l, h) + isInBetween;
    }
};