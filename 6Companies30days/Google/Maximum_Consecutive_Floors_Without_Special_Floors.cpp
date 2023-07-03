class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        int maxCon = 0;
        sort(special.begin(), special.end());
        maxCon = max(maxCon, special[0] - bottom);
        for (int i = 1; i < special.size(); i++)
        {
            maxCon = max(maxCon, special[i] - special[i - 1] - 1);
        }
        return max(maxCon, top - special.back());
    }
};