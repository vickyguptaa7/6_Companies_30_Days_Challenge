
class Solution
{
public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {
        int mxSum = -1e9;
        for (int i = 0; i < C; i++)
        {
            vector<int> row(R, 0);
            for (int j = i; j < C; j++)
            {
                for (int k = 0; k < R; k++)
                {
                    row[k] += M[k][j];
                }
                int sum = 0;
                for (int k = 0; k < R; k++)
                {
                    sum += row[k];
                    mxSum = max(mxSum, sum);
                    if (sum < 0)
                        sum = 0;
                }
            }
        }
        return mxSum;
    }
};