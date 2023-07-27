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
    int helper(TreeNode *root, int &mxSum)
    {
        if (!root)
            return 0;
        int left = helper(root->left, mxSum);
        int right = helper(root->right, mxSum);
        mxSum = max(
            {left + root->val, right + root->val, root->val, left + right + root->val, mxSum});
        return max({left + root->val, right + root->val, root->val});
    }

    int maxPathSum(TreeNode *root)
    {
        int mxSum = -1e9;
        helper(root, mxSum);
        return mxSum;
    }
};