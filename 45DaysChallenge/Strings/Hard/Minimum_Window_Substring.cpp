class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> freq(256, 0);
        vector<bool> isPresent(256, 0);
        for (auto x : t)
        {
            freq[x]++;
            isPresent[x] = true;
        }
        int counter = 0, prev = 0;
        for (auto x : isPresent)
            counter += x;
        int size = 1e9, start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isPresent[s[i]])
            {
                freq[s[i]]--;
                if (freq[s[i]] == 0)
                    counter--;
            }
            while (counter == 0)
            {
                if (size > i - prev + 1)
                {
                    size = i - prev + 1;
                    start = prev;
                }
                if (isPresent[s[prev]])
                {
                    freq[s[prev]]++;
                    if (freq[s[prev]] == 1)
                        counter++;
                }
                prev++;
            }
        }
        if (size == 1e9)
            return "";
        return s.substr(start, size);
    }
};