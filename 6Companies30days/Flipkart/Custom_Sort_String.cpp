class Solution
{
public:
    string customSortString(string order, string s)
    {
        map<char, int> freq;
        for (auto x : s)
            freq[x]++;
        string res;
        for (auto x : order)
        {
            if (freq.count(x))
            {
                for (int i = 0; i < freq[x]; i++)
                {
                    res += x;
                }
                freq.erase(x);
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (freq.count(s[i]))
                res += s[i];
        }
        return res;
    }
};