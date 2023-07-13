class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> output(n, 0);
        long long product = 1;
        output.back() = nums.back();
        for (int i = n - 2; i >= 0; i--)
            output[i] = output[i + 1] * nums[i];
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                output[i] = output[i + 1];
            }
            else if (i == n - 1)
            {
                output[i] = product;
            }
            else
            {
                output[i] = product * output[i + 1];
            }
            product *= nums[i];
        }
        return output;
    }
};