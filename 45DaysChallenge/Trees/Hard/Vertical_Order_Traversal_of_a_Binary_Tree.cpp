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
bool mycomp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<pair<int, int>>> mpp;
        queue<pair<TreeNode *, int>> que;
        que.push({root, 0});
        int level = 0;
        while (!que.empty())
        {
            int size = que.size();
            while (size--)
            {
                auto curr = que.front();
                que.pop();
                mpp[curr.second].push_back({curr.first->val, level});
                if (curr.first->left)
                    que.push({curr.first->left, curr.second - 1});
                if (curr.first->right)
                    que.push({curr.first->right, curr.second + 1});
            }
            level++;
        }
        vector<vector<int>> result;
        for (auto &x : mpp)
        {
            sort(x.second.begin(), x.second.end(), mycomp);
            vector<int> ncol;
            for (auto &y : x.second)
                ncol.push_back(y.first);
            result.push_back(ncol);
        }
        return result;
    }
};

class Solution
{
public:
    void helperDfs(TreeNode *root, int level, int position, map<int, map<int, vector<int>>> &traversalNodes)
    {
        if (!root)
        {
            return;
        }
        traversalNodes[position][level].push_back(root->val);
        helperDfs(root->left, level + 1, position - 1, traversalNodes);
        helperDfs(root->right, level + 1, position + 1, traversalNodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> nodes;
        map<int, map<int, vector<int>>> traversalNodes;
        helperDfs(root, 0, 0, traversalNodes);
        for (auto x : traversalNodes)
        {
            vector<int> temp;
            for (auto y : x.second)
            {
                sort(y.second.begin(), y.second.end());
                for (int i = 0; i < y.second.size(); i++)
                    temp.push_back(y.second[i]);
            }
            nodes.push_back(temp);
        }
        return nodes;
    }
};