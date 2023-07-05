class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int prev = 0;
        for (auto &num : nums)
        {
            if (nums[prev] == num)
                continue;
            prev++;
            nums[prev] = num;
        }
        return prev + 1;
    }
};