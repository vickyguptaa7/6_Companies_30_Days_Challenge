//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    bool helper(int indx, int size, int currsum, int target, int k, int a[], int taken)
    {
        if (k == 1 && indx == size)
        {
            if (currsum == target)
                return true;
            return false;
        }

        if (currsum == target)
        {
            return helper(0, size, 0, target, k - 1, a, taken);
        }

        if (indx == size)
            return false;

        if (helper(indx + 1, size, currsum, target, k, a, taken))
            return true;

        if (!((1 << indx) & taken) && currsum + a[indx] <= target && helper(indx + 1, size, currsum + a[indx], target, k, a, taken | (1 << indx)))
            return true;

        return false;
    }

    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum = accumulate(a, a + n, 0);
        if (sum % k != 0)
            return false;

        return helper(0, n, 0, sum / k, k, a, 0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.isKPartitionPossible(a, n, k) << endl;
    }
}
// } Driver Code Ends