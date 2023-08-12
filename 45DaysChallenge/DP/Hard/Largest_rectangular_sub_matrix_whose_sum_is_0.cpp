class Solution
{

    void compareAdd(int xs, int ys, int xe, int ye, vector<int> &cord)
    {
        if (cord.empty())
        {
            cord = {xs, ys, xe, ye};
            return;
        }
        int pxs = cord[0], pys = cord[1], pxe = cord[2], pye = cord[3];
        if ((xe - xs + 1) * (ye - ys + 1) > (pxe - pxs + 1) * (pye - pys + 1))
        {
            cord = {xs, ys, xe, ye};
        }
    }

public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a)
    {
        int r = a.size(), c = a[0].size();
        vector<int> cord;
        for (int i = 0; i < c; i++)
        {
            vector<int> row(r, 0);
            for (int j = i; j < c; j++)
            {
                for (int k = 0; k < r; k++)
                {
                    row[k] += a[k][j];
                }
                map<int, int> freq;
                int sum = 0;
                for (int k = 0; k < r; k++)
                {
                    sum += row[k];
                    if (freq.count(sum))
                    {
                        compareAdd(freq[sum] + 1, i, k, j, cord);
                    }
                    else
                    {
                        freq[sum] = k;
                    }
                    if (sum == 0)
                    {
                        compareAdd(0, i, k, j, cord);
                    }
                }
            }
        }
        if (cord.empty())
            return {};
        vector<vector<int>> res;
        for (int i = cord[0]; i <= cord[2]; i++)
        {
            vector<int> row;
            for (int j = cord[1]; j <= cord[3]; j++)
            {
                row.push_back(a[i][j]);
            }
            res.push_back(row);
        }
        return res;
    }
};