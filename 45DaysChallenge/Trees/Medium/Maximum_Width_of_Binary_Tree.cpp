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
    int widthOfBinaryTree(TreeNode *root)
    {
        long long mxWidth = 0;
        queue<pair<TreeNode *, long long>> que;
        que.push({root, 1});
        while (!que.empty())
        {
            int size = que.size();
            long long mx = INT_MIN, mn = INT_MAX;
            while (size--)
            {
                auto curr = que.front();
                que.pop();
                mn = min(mn, (long long)curr.second);
                mx = max(mx, (long long)curr.second);
                long long indx = curr.second - mn;
                if (curr.first->left)
                    que.push({curr.first->left, indx * 2});
                if (curr.first->right)
                    que.push({curr.first->right, indx * 2 + 1});
            }
            mxWidth = max(mxWidth, mx - mn + 1);
        }
        return mxWidth;
    }
};