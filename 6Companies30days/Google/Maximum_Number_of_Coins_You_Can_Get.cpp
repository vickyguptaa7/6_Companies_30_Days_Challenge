class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        int no = piles.size() / 3;
        int ans = 0, indx = (int)piles.size() - 2;
        while (no > 0)
        {
            ans += piles[indx];
            indx -= 2;
            no--;
        }
        return ans;
    }
};