class Solution
{

    vector<int> moveX = {0, 0, 1, -1};
    vector<int> moveY = {1, -1, 0, 0};

    void helper(int x, int y, int id, vector<vector<int>> &grid, vector<vector<int>> &visited, int &length)
    {
        int n = grid.size(), m = grid[0].size();
        visited[x][y] = id;
        length++;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + moveX[i], _y = y + moveY[i];
            if (_x >= n || _y >= m || _x < 0 || _y < 0 || visited[_x][_y] || !grid[_x][_y])
                continue;
            helper(_x, _y, id, grid, visited, length);
        }
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int id = 1;
        unordered_map<int, int> mpp;
        mpp[0] = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!grid[i][j] || visited[i][j])
                    continue;
                int length = 0;
                helper(i, j, id, grid, visited, length);
                mpp[id++] = length;
            }
        }
        int largest = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                    continue;
                unordered_set<int> oset;
                for (int k = 0; k < 4; k++)
                {
                    int _x = i + moveX[k], _y = j + moveY[k];
                    if (_x >= n || _y >= m || _x < 0 || _y < 0)
                        continue;
                    oset.insert(visited[_x][_y]);
                }
                int curr = 1;
                for (auto x : oset)
                {
                    curr += mpp[x];
                }
                largest = max(largest, curr);
            }
        }
        return largest == 0 ? m * n : largest;
    }
};