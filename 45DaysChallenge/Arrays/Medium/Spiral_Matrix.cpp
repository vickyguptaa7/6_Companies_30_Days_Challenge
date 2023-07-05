class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> spiral;
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, left = 0;
        int bottom = n - 1, right = m - 1;
        int total = n * m;
        while (total)
        {
            for (int i = left; i <= right && total > 0; i++)
            {
                total--;
                spiral.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom && total > 0; i++)
            {
                total--;
                spiral.push_back(matrix[i][right]);
            }
            right--;
            for (int i = right; i >= left && total > 0; i--)
            {
                total--;
                spiral.push_back(matrix[bottom][i]);
            }
            bottom--;
            for (int i = bottom; i >= top && total > 0; i--)
            {
                total--;
                spiral.push_back(matrix[i][left]);
            }
            left++;
        }
        return spiral;
    }
};