class Solution
{

    int helper(int src, int par, vector<int> list[], vector<int> &informTime)
    {
        int time = 0;
        for (auto child : list[src])
        {
            if (child == par)
                continue;
            time = max(time, helper(child, src, list, informTime));
        }
        return time + informTime[src];
    }

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<int> list[n];
        for (int i = 0; i < n; i++)
        {
            if (manager[i] == -1)
                continue;
            list[i].push_back(manager[i]);
            list[manager[i]].push_back(i);
        }
        return helper(headID, -1, list, informTime);
    }
};