class Solution
{
public:
    int power(int k, int p, int mod)
    {
        if (p == 0)
            return 1;
        if (p == 1)
            return k;
        if (p & 1)
        {
            return (k * pow(power(k, p / 2, mod), 2)) % mod;
        }
        else
        {
            return pow(power(k, p / 2, mod), 2) % mod;
        }
    }

    int division(int k, int p, int mod)
    {
        return power(k, power(p, mod - 2, mod), mod);
    }

    int strStr(string haystack, string needle)
    {
        int mod = 1e9 + 7, k = 101;
        int hash = 0;
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i < m; i++)
        {
            hash += (needle[i] - 'a') * power(k, i, mod);
            hash %= mod;
        }
        int hhash = 0;
        for (int i = 0; i < m; i++)
        {
            hhash += (haystack[i] - 'a') * power(k, i, mod);
            hhash %= mod;
        }
        cout << hash << "\n";
        for (int i = m; i < n; i++)
        {
            hhash -= (haystack[i - 1] - 'a');
            hhash = division(hhash, k, mod);
            hhash += (haystack[i] - 'a') * power(k, m - 1, mod);
            hhash %= mod;
            cout << hhash << "\n";
        }
        return 1;
    }
};