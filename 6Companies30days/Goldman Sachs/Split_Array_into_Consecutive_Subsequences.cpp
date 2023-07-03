class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> freq, nextNeed;
        for (auto x : nums)
            freq[x]++;

        for (auto x : nums)
        {
            if (!freq.count(x))
                continue;

            if (nextNeed.count(x))
            {
                nextNeed[x + 1]++;
                freq[x]--;
                nextNeed[x]--;
                if (nextNeed[x] == 0)
                    nextNeed.erase(x);
                if (freq[x] == 0)
                    freq.erase(x);
            }
            else if (freq.count(x) && freq.count(x + 1) && freq.count(x + 2))
            {
                freq[x]--;
                freq[x + 1]--;
                freq[x + 2]--;
                if (freq[x] == 0)
                    freq.erase(x);
                if (freq[x + 1] == 0)
                    freq.erase(x + 1);
                if (freq[x + 2] == 0)
                    freq.erase(x + 2);
                nextNeed[x + 3]++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};