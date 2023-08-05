class Solution
{

    bool isValid(int mid, vector<int> &heights, int bricks, int ladders)
    {
        vector<int> move;
        for (int i = 1; i <= mid; i++)
        {
            if (heights[i] - heights[i - 1] <= 0)
                continue;
            move.push_back(heights[i] - heights[i - 1]);
        }
        sort(move.begin(), move.end());
        for (int i = 0; i < (int)move.size() - ladders; i++)
        {
            bricks -= move[i];
        }
        return bricks >= 0;
    }

public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        int low = 0, high = n - 1, ans = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isValid(mid, heights, bricks, ladders))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};