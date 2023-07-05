class Solution
{
public:
    vector<int> moveX = {0, 0, -1, 1};
    vector<int> moveY = {-1, 1, 0, 0};

    bool wordFinder(int x, int y, int indx, string &word, vector<vector<bool>> &visit, vector<vector<char>> &board)
    {
        if (indx >= word.size())
            return true;
        visit[x][y] = true;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < 4; i++)
        {
            int _x = moveX[i] + x, _y = y + moveY[i];
            if (_x < 0 || _y < 0 || _x >= n || _y >= m || visit[_x][_y] || board[_x][_y] != word[indx])
                continue;

            if (wordFinder(_x, _y, indx + 1, word, visit, board))
                return true;
        }
        visit[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visit(rows, vector<bool>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (word[0] == board[i][j] && wordFinder(i, j, 1, word, visit, board))
                    return true;
            }
        }
        return false;
    }
};