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
    void helper(TreeNode *root, int &prev, int &minDiff)
    {
        if (!root)
            return;
        helper(root->left, prev, minDiff);
        if (prev != -1)
        {
            minDiff = min(minDiff, root->val - prev);
        }
        prev = root->val;
        helper(root->right, prev, minDiff);
    }

    int getMinimumDifference(TreeNode *root)
    {
        int minDiff = 1e9;
        int prev = -1;
        helper(root, prev, minDiff);
        return minDiff;
    }
};