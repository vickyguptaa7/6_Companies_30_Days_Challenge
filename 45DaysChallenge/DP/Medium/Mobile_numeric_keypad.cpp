class Solution
{

    vector<int> moveX = {0, 0, 0, -1, 1};
    vector<int> moveY = {0, -1, 1, 0, 0};
    vector<vector<bool>> keypad = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
        {0, 1, 0},
    };
    long long dp[4][3][25];

    long long helper(int x, int y, int N)
    {
        if (N == 0)
            return 1;

        if (dp[x][y][N] != -1)
            return dp[x][y][N];

        long long ways = 0;
        for (int i = 0; i < 5; i++)
        {
            int _x = x + moveX[i], _y = y + moveY[i];
            if (_x >= 4 || _y >= 3 || _x < 0 || _y < 0 || !keypad[_x][_y])
                continue;
            ways += helper(_x, _y, N - 1);
        }
        return dp[x][y][N] = ways;
    }

public:
    long long getCount(int N)
    {
        memset(dp, -1, sizeof(dp));
        long long ways = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (!keypad[i][j])
                    continue;
                ways += helper(i, j, N - 1);
            }
        }
        return ways;
    }
};