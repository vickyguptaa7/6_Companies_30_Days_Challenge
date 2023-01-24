class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> distance(n + 1, 1e9);
        vector<pair<int, int>> list[n + 1];
        for (auto x : times)
        {
            list[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pque;
        pque.push({0, k});
        distance[k] = 0;
        while (!pque.empty())
        {
            auto curr = pque.top();
            pque.pop();
            for (auto x : list[curr.second])
            {
                if (curr.first + x.second < distance[x.first])
                {
                    distance[x.first] = curr.first + x.second;
                    pque.push({distance[x.first], x.first});
                }
            }
        }
        int mx = *max_element(distance.begin() + 1, distance.end());
        return mx == 1e9 ? -1 : mx;
    }
};