/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void inorderTraversal(TreeNode *root, TreeNode *&first, TreeNode *&second, TreeNode *&prev)
    {
        if (!root)
            return;
        inorderTraversal(root->left, first, second, prev);
        if (prev && prev->val > root->val)
        {
            if (!first)
            {
                first = prev;
                second = root;
            }
            else
            {
                second = root;
            }
        }
        prev = root;
        inorderTraversal(root->right, first, second, prev);
    }

    void recoverTree(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *left = nullptr, *right = nullptr, *prev = nullptr;
        inorderTraversal(root, left, right, prev);
        swap(left->val, right->val);
    }
};