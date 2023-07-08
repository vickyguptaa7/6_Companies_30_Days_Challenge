class Solution
{
public:
    void balanced(int open, int close, string ans, vector<string> &answer)
    {

        if (open == 0 && close == 0)
        {
            answer.push_back(ans);
            return;
        }

        if (open > 0)
            balanced(open - 1, close, ans + "(", answer);
        if (close > open)
            balanced(open, close - 1, ans + ")", answer);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> answer;
        balanced(n - 1, n, "(", answer);
        return answer;
    }
};