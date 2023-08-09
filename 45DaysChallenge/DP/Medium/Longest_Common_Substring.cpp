class Solution
{

    int helper(int indx1, int indx2, string &s1, string &s2, vector<vector<int>> &dp, int &mxCommon)
    {
        if (indx1 == s1.size() || indx2 == s2.size())
            return 0;

        if (dp[indx1][indx2] != -1)
            return dp[indx1][indx2];

        int common = 0, diff = 0;

        if (s1[indx1] == s2[indx2])
        {
            common = helper(indx1 + 1, indx2 + 1, s1, s2, dp, mxCommon) + 1;
        }

        diff = max(helper(indx1 + 1, indx2, s1, s2, dp, mxCommon),
                   helper(indx1, indx2 + 1, s1, s2, dp, mxCommon));

        mxCommon = max({mxCommon, common, diff});

        if (common >= diff)
            return dp[indx1][indx2] = common;

        return 0;
    }

public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int mxCommon = 0;
        helper(0, 0, S1, S2, dp, mxCommon);
        return mxCommon;
    }
};