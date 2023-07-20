class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(i);

        while (st.size() > 1)
        {
            int c1 = st.top();
            st.pop();
            int c2 = st.top();
            st.pop();

            if (!M[c1][c2])
                st.push(c1);
            else
                st.push(c2);
        }
        int p1 = st.top();
        for (int i = 0; i < n; i++)
        {
            if (i == p1)
                continue;
            if (M[p1][i] == 1 || M[i][p1] == 0)
            {
                return -1;
            }
        }
        return p1;
    }
};