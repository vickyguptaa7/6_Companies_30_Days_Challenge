class Solution
{

    void helper(int src, vector<bool> &visit, vector<int> adj[], vector<int> &dfs)
    {
        dfs.push_back(src);
        visit[src] = true;
        for (auto child : adj[src])
        {
            if (visit[child])
                continue;
            helper(child, visit, adj, dfs);
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> dfs;
        vector<bool> visit(V, 0);
        helper(0, visit, adj, dfs);
        return dfs;
    }
};