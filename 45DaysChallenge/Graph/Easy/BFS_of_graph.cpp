class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        queue<int> que;
        que.push(0);
        vector<int> bfs;
        vector<int> visit(V);
        visit[0] = true;
        while (!que.empty())
        {
            int curr = que.front();
            que.pop();
            bfs.push_back(curr);
            for (auto child : adj[curr])
            {
                if (visit[child])
                    continue;
                visit[child] = true;
                que.push(child);
            }
        }
        return bfs;
    }
};