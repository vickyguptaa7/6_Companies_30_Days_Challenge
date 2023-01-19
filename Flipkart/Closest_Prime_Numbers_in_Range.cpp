class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        int n = 1e6;
        vector<int> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (long long i = 2; i <= n; i++)
        {
            if (prime[i] == 1)
            {
                prime[i] = i;
                for (long long j = i * i; j <= n; j += i)
                    if (prime[j] == 1)
                        prime[j] = i;
            }
        }
        vector<int> result;
        for (int i = left; i <= right; i++)
        {
            if (prime[i] == i)
                result.push_back(i);
        }
        if (result.empty() || result.size() == 1)
        {
            return {-1, -1};
        }
        int mn = 1e9;
        for (int i = 1; i < result.size(); i++)
        {
            mn = min(mn, result[i] - result[i - 1]);
        }
        for (int i = 1; i < result.size(); i++)
        {
            if (mn == result[i] - result[i - 1])
            {
                return {result[i - 1], result[i]};
            }
        }
        return {-1, -1};
    }
};