class Solution
{
public:
    pair<int, int> preCalc(int src, int par, vector<int> list[], vector<int> &node_count,
                           vector<int> &node_distance)
    {
        int ncnt = 1, ndist = 0;
        for (auto x : list[src])
        {
            if (par != x)
            {
                auto val = preCalc(x, src, list, node_count, node_distance);
                ncnt += val.first;
                ndist += val.second + val.first;
            }
        }
        node_count[src] = ncnt;
        node_distance[src] = ndist;
        return {ncnt, ndist};
    }
    void helper(int src, int par, int n, vector<int> list[], vector<int> &node_count,
                vector<int> &node_distance)
    {
        for (auto x : list[src])
        {
            if (par != x)
            {
                /*
                consider parent as child node and child as parent (n-nodeCnt)
                now child is parent so we have to decrement the res nodeCnt as we move
                one step closer to the other one.. and in above we added bcoz we move one
                step further from the as now child is parent
                */
                node_distance[x] = (n - node_count[x]) + (-node_count[x]) + node_distance[src];
                helper(x, src, n, list, node_count, node_distance);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<int> list[n];
        for (auto x : edges)
        {
            list[x[0]].push_back(x[1]);
            list[x[1]].push_back(x[0]);
        }
        vector<int> node_distance(n, 0), node_count(n, 0);
        preCalc(0, -1, list, node_count, node_distance);
        helper(0, -1, n, list, node_count, node_distance);
        return node_distance;
    }
};