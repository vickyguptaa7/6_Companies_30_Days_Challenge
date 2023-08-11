class Solution
{
    int dp[500][500];

    int helper(int i1, int i2, string &s, string &r)
    {
        if (i1 == s.size() || i2 == r.size())
            return 0;

        if (dp[i1][i2] != -1)
            return dp[i1][i2];

        int ways = max(helper(i1 + 1, i2, s, r), helper(i1, i2 + 1, s, r));

        if (s[i1] == r[i2])
            ways = max(ways, helper(i1 + 1, i2 + 1, s, r) + 1);

        return dp[i1][i2] = ways;
    }

public:
    int minInsertions(string s)
    {
        string r = s;
        reverse(r.begin(), r.end());
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return n - helper(0, 0, s, r);
    }
};