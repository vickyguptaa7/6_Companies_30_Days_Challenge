class Solution
{
    bool isOperator(char op)
    {
        return op == '*' || op == '+' || op == '/' || op == '-';
    }

    int afterOperation(int num1, int num2, char op)
    {
        switch (op)
        {
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        }
        return 0;
    }

public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for (auto op : S)
        {
            if (isOperator(op))
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(afterOperation(n2, n1, op));
            }
            else
            {
                st.push(op - '0');
            }
        }
        return st.top();
    }
};