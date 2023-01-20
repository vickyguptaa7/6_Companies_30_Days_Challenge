class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        set<int> oset;
        int prev = 0;
        for (int i = k - 1; i < s.size(); i++)
        {
            int val = 0, pow2 = 1;
            for (int j = i; j >= prev; j--)
            {
                if (s[j] == '1')
                    val += pow2;
                pow2 *= 2;
            }
            oset.insert(val);
            prev++;
        }
        return (1 << k) == oset.size();
    }
};