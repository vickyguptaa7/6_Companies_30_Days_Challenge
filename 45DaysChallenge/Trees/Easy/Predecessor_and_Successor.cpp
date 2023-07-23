class Solution
{
    void findPre(Node *root, Node *&pre, int key)
    {
        if (!root)
            return;
        if (root->key < key)
        {
            pre = root;
            findPre(root->right, pre, key);
        }
        else
        {
            findPre(root->left, pre, key);
        }
    }
    void findSuc(Node *root, Node *&suc, int key)
    {
        if (!root)
            return;
        if (root->key > key)
        {
            suc = root;
            findSuc(root->left, suc, key);
        }
        else
        {
            findSuc(root->right, suc, key);
        }
    }

public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        findPre(root, pre, key);
        findSuc(root, suc, key);
    }
};