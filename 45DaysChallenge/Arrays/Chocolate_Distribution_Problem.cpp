class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        long long diff = 1e18;
        for (int i = m - 1; i < n; i++)
        {
            diff = min(diff, a[i] - a[i - m + 1]);
        }
        return diff;
    }
};