//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void helper(int indx, string &str, int k, string &ans)
    {
        if (indx + 1 == str.size() || k == 0)
        {
            ans = max(ans, str);
            return;
        }
        helper(indx + 1, str, k, ans);
        char mx = '0';
        for (int i = indx + 1; i < str.size(); i++)
            mx = max(mx, str[i]);

        for (int i = indx + 1; i < str.size(); i++)
        {
            if (str[i] == mx)
            {
                swap(str[indx], str[i]);
                helper(indx + 1, str, k - 1, ans);
                swap(str[indx], str[i]);
            }
        }
    }

    // Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        string ans = str;
        helper(0, str, k, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends