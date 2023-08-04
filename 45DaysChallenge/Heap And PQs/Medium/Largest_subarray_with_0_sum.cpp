class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        unordered_map<int, int> mmp;
        mmp[0] = -1;
        int sum = 0, len = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (mmp.count(sum))
                len = max(len, i - mmp[sum]);
            else
                mmp[sum] = i;
        }
        return len;
    }
};