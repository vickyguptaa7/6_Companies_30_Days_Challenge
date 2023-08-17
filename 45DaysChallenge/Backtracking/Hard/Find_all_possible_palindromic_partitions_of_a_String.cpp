//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    vector<vector<string>> result;
    vector<string> curr;

public:
    bool isPalindrome(string &S, int s, int e)
    {
        while (s <= e && S[s] == S[e])
        {
            s++;
            e--;
        }
        return s > e;
    }

    void helper(int indx, string &S)
    {
        if (indx == S.size())
        {
            result.push_back(curr);
            return;
        }

        string word;
        for (int i = indx; i < S.size(); i++)
        {
            word += S[i];
            if (isPalindrome(S, indx, i))
            {
                curr.push_back(word);
                helper(i + 1, S);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> allPalindromicPerms(string S)
    {
        helper(0, S);
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;

        cin >> S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);

        for (int i = 0; i < ptr.size(); i++)
        {
            for (int j = 0; j < ptr[i].size(); j++)
            {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends