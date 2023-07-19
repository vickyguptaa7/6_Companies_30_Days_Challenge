class Solution
{
public:
    vector<int> findNextSmallerLeft(vector<int> &arr)
    {
        vector<int> next;
        stack<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if (st.empty())
                next.push_back(-1);
            else
                next.push_back(st.top());
            st.push(i);
        }
        return next;
    }
    vector<int> findNextSmallerRight(vector<int> &arr)
    {
        vector<int> next;
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                next.push_back(arr.size());
            else
                next.push_back(st.top());
            st.push(i);
        }
        reverse(next.begin(), next.end());
        return next;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        vector<int> nextml = findNextSmallerLeft(arr);
        vector<int> nextmr = findNextSmallerRight(arr);
        long long result = 0, mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++)
        {
            int left = i - nextml[i];
            int right = nextmr[i] - i;
            result += (left * 1ll * right * 1ll * arr[i]) % mod;
            result %= mod;
        }
        return result;
    }
};