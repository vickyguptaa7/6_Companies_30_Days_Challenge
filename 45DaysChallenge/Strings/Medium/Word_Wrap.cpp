class Solution
{
public:
    int helper(int indx, vector<int> &nums, int k, vector<int> &dp)
    {
        if (indx == nums.size())
            return 0;
        if (dp[indx] != -1)
            return dp[indx];
        int sum = 0;
        int mn = 1e9;
        int incld = -1;
        for (int i = indx; i < nums.size(); i++)
        {
            incld++;
            sum += nums[i];
            if (sum + incld > k)
                break;
            int cost = (k - sum - incld) * (k - sum - incld);
            int further = helper(i + 1, nums, k, dp);
            mn = min(mn, i + 1 == nums.size() ? further : further + cost);
        }
        return dp[indx] = mn;
    }

    int solveWordWrap(vector<int> nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, k, dp);
    }
};