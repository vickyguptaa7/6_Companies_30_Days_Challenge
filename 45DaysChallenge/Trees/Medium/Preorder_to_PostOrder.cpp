class Solution
{

    Node *insertBST(Node *root, int val)
    {
        if (!root)
            return newNode(val);

        if (root->data > val)
            root->left = insertBST(root->left, val);
        else
            root->right = insertBST(root->right, val);

        return root;
    }

public:
    // Function that constructs BST from its preorder traversal.
    Node *post_order(int pre[], int size)
    {
        Node *root = newNode(pre[0]);
        for (int i = 1; i < size; i++)
        {
            insertBST(root, pre[i]);
        }
        return root;
    }
};