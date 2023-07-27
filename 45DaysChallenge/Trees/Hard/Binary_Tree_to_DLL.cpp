class Solution
{
public:
    // Function to convert binary tree to doubly linked list and return it.
    void helper(Node *root, Node *&prev, Node *&head)
    {
        if (!root)
            return;

        helper(root->left, prev, head);
        if (prev)
        {
            prev->right = root;
            root->left = prev;
        }
        else
        {
            head = root;
        }
        prev = root;
        helper(root->right, prev, head);
    }
    Node *bToDLL(Node *root)
    {
        Node *prev = nullptr, *head = nullptr;
        helper(root, prev, head);
        return head;
    }
};
