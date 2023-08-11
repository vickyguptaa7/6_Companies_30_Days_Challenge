//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    int dp[100][100];
    int preSum[101];
    int helper(int s, int e, int lvl, int keys[], int freq[])
    {
        if (s > e)
            return 0;

        if (dp[s][e] != -1)
            return dp[s][e];

        int mn = 1e9;
        for (int i = s; i <= e; i++)
        {
            mn = min(mn, helper(s, i - 1, lvl + 1, keys, freq) +
                             helper(i + 1, e, lvl + 1, keys, freq) + preSum[e + 1] - preSum[s]);
        }

        return dp[s][e] = mn;
    }

public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        memset(dp, -1, sizeof(dp));
        memset(preSum, 0, sizeof(preSum));
        for (int i = 1; i <= n; i++)
            preSum[i] += preSum[i - 1] + freq[i - 1];
        return helper(0, n - 1, 1, keys, freq);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for (int i = 0; i < n; i++)
            cin >> keys[i];
        int freq[n];
        for (int i = 0; i < n; i++)
            cin >> freq[i];
        Solution ob;
        cout << ob.optimalSearchTree(keys, freq, n) << endl;
    }
    return 0;
}
// } Driver Code Ends