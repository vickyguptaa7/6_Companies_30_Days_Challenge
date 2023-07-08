class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int len = strs[0].size();
        for (int i = 1; i < strs.size(); i++)
        {
            for (int j = 0; j < min(strs[i].size(), strs[0].size()); j++)
            {
                if (strs[0][j] != strs[i][j])
                {
                    len = min(len, j);
                    break;
                }
            }
            len = min(len, (int)strs[i].size());
        }
        return strs[0].substr(0, len);
    }
};