class Solution
{
public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int colour[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (colour[i] == 0)
            {
                if (!DFS_Bipartite(i, -1, adj, colour))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool DFS_Bipartite(int src, int parent, vector<int> adj[], int colour[])
    {
        if (parent == -1)
            colour[src] = 1;
        else
            colour[src] = (colour[parent] == 1) ? 2 : 1;
        for (auto node : adj[src])
        {
            if (parent == node)
            {
                continue;
            }
            else if (colour[node] == 0)
            {
                if (!DFS_Bipartite(node, src, adj, colour))
                    return false;
            }
            else
            {
                if (colour[src] == colour[node])
                    return false;
            }
        }
        return true;
    }
};