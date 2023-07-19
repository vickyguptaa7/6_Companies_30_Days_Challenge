class Solution
{
public:
    int helper(int strt, int end, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (strt >= end)
            return 0;

        if (dp[strt][end] != -1)
            return dp[strt][end];

        int ways = INT_MAX;
        for (int i = strt; i < end; i++)
        {
            ways = min(ways, helper(strt, i, arr, dp) + helper(i + 1, end, arr, dp) +
                                 (*max_element(arr.begin() + strt, arr.begin() + i + 1)) *
                                     (*max_element(arr.begin() + i + 1, arr.begin() + end + 1)));
        }
        return dp[strt][end] = ways;
    }

    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n - 1, arr, dp);
    }
};