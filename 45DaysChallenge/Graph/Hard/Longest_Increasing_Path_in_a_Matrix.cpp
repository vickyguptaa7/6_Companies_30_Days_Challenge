class Solution
{

    vector<int> moveX = {0, 0, -1, 1};
    vector<int> moveY = {1, -1, 0, 0};

public:
    int helper(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        int n = matrix.size(), m = matrix[0].size();
        int path = 0;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + moveX[i], _y = y + moveY[i];
            if (_x >= n || _y >= m || _x < 0 || _y < 0 || matrix[_x][_y] <= matrix[x][y])
                continue;
            path = max(path, 1 + helper(_x, _y, matrix, dp));
        }
        return dp[x][y] = path;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int path = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                path = max(path, 1 + helper(i, j, matrix, dp));
            }
        }
        return path;
    }
};