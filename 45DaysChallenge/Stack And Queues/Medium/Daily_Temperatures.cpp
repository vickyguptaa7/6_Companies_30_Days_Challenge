class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> nextg;
        stack<int> temp;
        int n = temperatures.size();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!temp.empty() && temperatures[temp.top()] <= temperatures[i])
            {
                temp.pop();
            }
            if (temp.empty())
                nextg.push_back(n);
            else
                nextg.push_back(temp.top());
            temp.push(i);
        }
        reverse(nextg.begin(), nextg.end());
        for (int i = 0; i < n; i++)
        {
            if (nextg[i] == n)
                nextg[i] = 0;
            else
                nextg[i] = nextg[i] - i;
        }
        return nextg;
    }
};