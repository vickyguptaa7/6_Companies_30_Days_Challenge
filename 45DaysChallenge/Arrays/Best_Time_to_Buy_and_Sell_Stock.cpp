class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mn = prices[0], profit = 0;
        for (auto x : prices)
        {
            profit = max(x - mn, profit);
            mn = min(mn, x);
        }
        return profit;
    }
};