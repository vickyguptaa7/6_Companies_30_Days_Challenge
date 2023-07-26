class Solution
{
    bool findRootToNodePath(Node *root, int node, vector<int> &path)
    {
        if (!root)
            return 0;

        if (node == root->data)
        {
            path.push_back(root->data);
            return true;
        }

        if (findRootToNodePath(root->left, node, path))
        {
            path.push_back(root->data);
            return true;
        }

        if (findRootToNodePath(root->right, node, path))
        {
            path.push_back(root->data);
            return true;
        }

        return false;
    }

public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node *root, int a, int b)
    {
        vector<int> patha, pathb;
        findRootToNodePath(root, a, patha);
        findRootToNodePath(root, b, pathb);
        reverse(patha.begin(), patha.end());
        reverse(pathb.begin(), pathb.end());
        int indx = min(patha.size(), pathb.size());
        for (int i = 0; i < min(patha.size(), pathb.size()); i++)
        {
            if (patha[i] != pathb[i])
            {
                indx = i;
                break;
            }
        }
        return patha.size() + pathb.size() - 2 * indx;
    }
};