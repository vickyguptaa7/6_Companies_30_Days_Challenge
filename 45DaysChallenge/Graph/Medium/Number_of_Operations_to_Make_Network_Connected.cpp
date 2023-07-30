class Solution
{

    void dfsHelper(int src, int par, vector<int> list[], vector<bool> &visited, int &edgeCnt, int &nodeCnt)
    {
        visited[src] = true;
        nodeCnt++;
        for (auto child : list[src])
        {
            edgeCnt++;
            if (visited[child])
                continue;
            dfsHelper(child, src, list, visited, edgeCnt, nodeCnt);
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int extra = 0;
        int components = 0;
        vector<int> list[n];
        for (auto edge : connections)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            components++;
            int edgeCnt = 0, nodeCnt = 0;
            dfsHelper(i, -1, list, visited, edgeCnt, nodeCnt);
            edgeCnt /= 2;
            extra += (edgeCnt - nodeCnt + 1);
        }
        if (extra >= components - 1)
            return components - 1;
        return -1;
    }
};