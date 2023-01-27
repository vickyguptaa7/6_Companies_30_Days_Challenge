class Solution
{
public:
    int maxSum(vector<vector<int>> &grid)
    {
        int maxSum = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i <= n - 3; i++)
        {
            for (int j = 0; j <= m - 3; j++)
            {
                int sum = 0;
                for (int p = i; p < i + 3; p++)
                {
                    for (int q = j; q < j + 3; q++)
                    {
                        sum += grid[p][q];
                    }
                }
                sum -= grid[i + 1][j] + grid[i + 1][j + 2];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};