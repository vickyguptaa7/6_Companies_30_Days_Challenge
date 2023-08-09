class Solution
{
    int dp[10002];

    int helper(int n, int x, int y, int z)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int mxCuts = -1e9;
        if (n >= x)
            mxCuts = max(mxCuts, 1 + helper(n - x, x, y, z));
        if (n >= y)
            mxCuts = max(mxCuts, 1 + helper(n - y, x, y, z));
        if (n >= z)
            mxCuts = max(mxCuts, 1 + helper(n - z, x, y, z));

        return dp[n] = mxCuts;
    }

public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp, -1, sizeof(dp));
        int res = helper(n, x, y, z);
        return res < 0 ? 0 : res;
    }
};