bool helper(Node *root, int start, int end)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return root->data - 1 <= start && root->data + 1 >= end;
    }
    return helper(root->left, start, root->data) |
           helper(root->right, root->data, end);
}

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    return helper(root, 0, 20000);
}