class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> visited(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
        pque.push({0, 0});
        int treeCost = 0;
        while (!pque.empty())
        {
            auto cost = pque.top().first;
            auto curr = pque.top().second;
            pque.pop();
            if (visited[curr])
                continue;
            treeCost += cost;
            visited[curr] = true;
            for (auto child : adj[curr])
            {
                if (visited[child[0]])
                    continue;
                pque.push({child[1], child[0]});
            }
        }
        return treeCost;
    }
};