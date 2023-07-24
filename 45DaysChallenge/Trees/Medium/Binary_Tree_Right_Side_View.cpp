class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> right;
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            int currv;
            while (size--)
            {
                auto curr = que.front();
                que.pop();
                currv = curr->data;
                if (curr->left)
                    que.push(curr->left);
                if (curr->right)
                    que.push(curr->right);
            }
            right.push_back(currv);
        }
        return right;
    }
};