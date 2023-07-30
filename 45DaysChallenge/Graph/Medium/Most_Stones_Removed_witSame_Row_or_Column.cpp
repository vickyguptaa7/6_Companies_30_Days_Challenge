class Solution
{
    void helper(int src, vector<int> list[], vector<int> &visited, int &nodeCnt)
    {
        visited[src] = true;
        nodeCnt++;
        for (auto child : list[src])
        {
            if (visited[child])
                continue;
            helper(child, list, visited, nodeCnt);
        }
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<int> list[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        vector<int> visited(n, 0);
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            int nodeCnt = 0;
            if (visited[i])
                continue;
            helper(i, list, visited, nodeCnt);
            mx += nodeCnt - 1;
        }
        return mx;
    }
};