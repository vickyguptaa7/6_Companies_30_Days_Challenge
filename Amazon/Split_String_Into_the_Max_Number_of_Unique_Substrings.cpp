class Solution
{
public:
    int helper(int iter, string &s, set<string> &oset)
    {
        if (iter == s.size())
            return 0;
        int splits = -1e9;
        string substr;
        for (int i = iter; i < s.size(); i++)
        {
            substr += s[i];
            if (!oset.count(substr))
            {
                oset.insert(substr);
                splits = max(splits, helper(i + 1, s, oset) + 1);
                oset.erase(substr);
            }
        }
        return splits;
    }
    int maxUniqueSplit(string s)
    {
        set<string> oset;
        return helper(0, s, oset);
    }
};