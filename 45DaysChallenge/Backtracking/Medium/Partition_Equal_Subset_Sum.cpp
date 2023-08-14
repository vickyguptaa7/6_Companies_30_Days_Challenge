// User function Template for C++

class Solution
{

    int dp[100][10000];

public:
    int helper(int indx, int sum, int arr[])
    {
        if (sum == 0)
            return 1;

        if (indx == -1)
            return 0;

        if (dp[indx][sum] != -1)
            return dp[indx][sum];

        if (sum >= arr[indx])
        {
            return dp[indx][sum] = helper(indx - 1, sum - arr[indx], arr) || helper(indx - 1, sum, arr);
        }
        else
        {
            return dp[indx][sum] = helper(indx - 1, sum, arr);
        }
    }

    int equalPartition(int N, int arr[])
    {
        int sum = accumulate(arr, arr + N, 0ll);
        if (sum & 1)
            return 0;
        memset(dp, -1, sizeof(dp));
        return helper(N - 1, sum / 2, arr);
    }
};