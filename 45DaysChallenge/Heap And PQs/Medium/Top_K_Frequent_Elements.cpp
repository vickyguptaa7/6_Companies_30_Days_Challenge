class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (auto x : nums)
            freq[x]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
        for (auto x : freq)
        {
            pque.push({x.second, x.first});
            if (pque.size() > k)
                pque.pop();
        }
        vector<int> res;
        while (!pque.empty())
        {
            res.push_back(pque.top().second);
            pque.pop();
        }
        return res;
    }
};