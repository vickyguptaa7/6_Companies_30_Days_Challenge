typedef pair<int, string> ppis;

struct Mycomp
{
    bool operator()(ppis &a, ppis &b)
    {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        priority_queue<ppis, vector<ppis>, Mycomp> pque;
        map<string, int> freq;
        for (int i = 0; i < words.size(); i++)
        {
            freq[words[i]]++;
        }
        for (auto x : freq)
        {
            pque.push({x.second, x.first});
            if (pque.size() > k)
                pque.pop();
        }
        vector<string> result;
        while (!pque.empty())
            result.push_back(pque.top().second), pque.pop();
        reverse(result.begin(), result.end());
        return result;
    }
};