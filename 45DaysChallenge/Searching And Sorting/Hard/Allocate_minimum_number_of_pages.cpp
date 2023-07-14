class Solution
{
    bool isValid(int A[], int n, int m, long long books)
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (sum > books)
            {
                sum = A[i];
                m--;
            }
        }
        return m > 0;
    }

public:
    // Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    {
        if (N < M)
            return -1;
        long long low = *max_element(A, A + N), high = accumulate(A, A + N, 0ll), ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (isValid(A, N, M, mid))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};