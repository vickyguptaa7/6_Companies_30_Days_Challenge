class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto x : s)
        {
            if (!st.empty() && (x == ']' || x == '}' || x == ')'))
            {
                if ((x == ']' && st.top() == '[') || (x == '}' && st.top() == '{') ||
                    (x == ')' && st.top() == '('))
                    st.pop();
                else
                    return false;
            }
            else
            {
                st.push(x);
            }
        }
        return st.empty();
    }
};