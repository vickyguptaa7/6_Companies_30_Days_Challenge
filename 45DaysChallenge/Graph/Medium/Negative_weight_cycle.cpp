class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> distance(n, 1e9);
        distance[0] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < edges.size(); j++)
            {
                if (distance[edges[j][1]] > distance[edges[j][0]] + edges[j][2])
                    distance[edges[j][1]] = distance[edges[j][0]] + edges[j][2];
            }
        }
        for (int j = 0; j < edges.size(); j++)
        {
            if (distance[edges[j][1]] > distance[edges[j][0]] + edges[j][2])
                return true;
        }
        return false;
    }
};