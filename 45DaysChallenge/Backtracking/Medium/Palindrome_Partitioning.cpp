class Solution
{
public:
    bool isPalindrome(string &str, int s, int e)
    {
        while (s <= e && str[s] == str[e])
        {
            s++;
            e--;
        }
        return (s > e);
    }

    void helper(int indx, string &s, vector<string> &curr, vector<vector<string>> &result)
    {
        if (indx == s.size())
        {
            result.push_back(curr);
            return;
        }

        string word;
        for (int i = indx; i < s.size(); i++)
        {
            word += s[i];
            if (isPalindrome(s, indx, i))
            {
                curr.push_back(word);
                helper(i + 1, s, curr, result);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> curr;
        helper(0, s, curr, result);
        return result;
    }
};