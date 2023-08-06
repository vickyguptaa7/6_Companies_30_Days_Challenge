class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        map<string, vector<string>> res;
        for (auto &str : string_list)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            res[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto x : res)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};