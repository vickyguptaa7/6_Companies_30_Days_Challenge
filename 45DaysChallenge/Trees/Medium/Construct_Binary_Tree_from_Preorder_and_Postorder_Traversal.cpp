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
    TreeNode *helper(int &preIndx, int &postIndx, vector<int> &pre, vector<int> &pos)
    {
        TreeNode *root = new TreeNode(pre[preIndx++]);
        if (root->val != pos[postIndx])
            root->left = helper(preIndx, postIndx, pre, pos);
        if (root->val != pos[postIndx])
            root->right = helper(preIndx, postIndx, pre, pos);
        postIndx++;
        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int preIndx = 0, postIndx = 0;
        return helper(preIndx, postIndx, preorder, postorder);
    }
};