class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        vector<int> mx(nums.size(), INT_MIN);
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--)
        {
            mx[i] = max(mx[i + 1], nums[i + 1]);
        }
        int mn = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (mn < nums[i] && nums[i] < mx[i])
            {
                return true;
            }
            mn = min(mn, nums[i]);
        }
        return false;
    }
};