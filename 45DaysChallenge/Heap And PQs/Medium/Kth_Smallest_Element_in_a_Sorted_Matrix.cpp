class Solution
{

    int isValid(int ele, vector<vector<int>> &mat)
    {
        int cntr = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            int indx = upper_bound(mat[i].begin(), mat[i].end(), ele) - mat[i].begin();
            if (indx == 0)
                break;
            cntr += indx;
        }
        return cntr;
    }

public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int low = -1e9, high = 1e9, ans = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isValid(mid, matrix) >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};