class Solution
{
    vector<int> moveX = {0, 0, -1, 1};
    vector<int> moveY = {1, -1, 0, 0};

    void helper(int x, int y, vector<vector<char>> &grid, vector<vector<int>> &visited)
    {
        int n = grid.size(), m = grid[0].size();
        visited[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + moveX[i], _y = y + moveY[i];
            if (_x >= n || _y >= m || _x < 0 || _y < 0 || grid[_x][_y] == '0' || visited[_x][_y])
                continue;
            helper(_x, _y, grid, visited);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int island = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] || grid[i][j] == '0')
                    continue;
                island++;
                helper(i, j, grid, visited);
            }
        }
        return island;
    }
};