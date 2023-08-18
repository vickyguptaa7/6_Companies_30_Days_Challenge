class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> freq;
        int mx = 0, prev = 0;
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i]]++;
            int total = 0, highest = 0;
            for (auto x : freq)
            {
                total += x.second;
                highest = max(highest, x.second);
            }
            total -= highest;
            if (total > k)
            {
                freq[s[prev]]--;
                if (freq[s[prev]] == 0)
                    freq.erase(s[prev]);
                prev++;
                freq[s[i]]--;
                if (freq[s[i]] == 0)
                    freq.erase(s[i]);
                i--;
            }
            mx = max(i - prev + 1, mx);
        }
        return mx;
    }
};