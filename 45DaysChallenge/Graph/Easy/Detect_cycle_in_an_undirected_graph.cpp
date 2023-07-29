class Solution
{

    bool helper(int src, int par, vector<int> list[], vector<int> &visited)
    {
        visited[src] = true;
        for (auto child : list[src])
        {
            if (child == par)
            {
                continue;
            }
            if (visited[child])
                return true;

            if (helper(child, src, list, visited))
                return true;
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && helper(i, -1, adj, visited))
                return true;
        }
        return false;
    }
};