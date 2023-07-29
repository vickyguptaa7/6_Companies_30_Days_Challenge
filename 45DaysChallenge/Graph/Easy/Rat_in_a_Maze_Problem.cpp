class Solution
{
    vector<int> moveX = {0, 0, -1, 1};
    vector<int> moveY = {1, -1, 0, 0};
    vector<char> move = {'R', 'L', 'U', 'D'};

    void helper(int x, int y, int n, string &path, vector<vector<int>> &m, vector<vector<int>> &visited,
                vector<string> &results)
    {
        if (x + 1 == n && y + 1 == n)
        {
            results.push_back(path);
            return;
        }
        visited[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + moveX[i], _y = y + moveY[i];
            if (_x >= n || _y >= n || _x < 0 || _y < 0 || m[_x][_y] == 0 || visited[_x][_y])
                continue;
            path.push_back(move[i]);
            helper(_x, _y, n, path, m, visited, results);
            path.pop_back();
        }
        visited[x][y] = false;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> results;
        if (!m[0][0])
            return results;
        string path = "";
        vector<vector<int>> visited(n, vector<int>(n, 0));
        helper(0, 0, n, path, m, visited, results);
        return results;
    }
};
