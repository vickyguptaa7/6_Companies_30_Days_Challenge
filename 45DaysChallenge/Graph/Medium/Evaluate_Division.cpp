class Solution
{

    double helper(string src, string &tar, map<string, bool> &visited, map<string, vector<pair<string, double>>> &list)
    {
        if (!list.count(src) || !list.count(tar))
            return -1;
        if (src == tar)
            return 1;
        visited[src] = true;
        for (auto child : list[src])
        {
            if (visited[child.first])
                continue;

            double val = helper(child.first, tar, visited, list);

            if (val != -1)
            {
                visited[src] = false;
                return val * child.second;
            }
        }
        visited[src] = false;
        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        map<string, vector<pair<string, double>>> list;
        map<string, bool> visited;
        for (int i = 0; i < equations.size(); i++)
        {
            list[equations[i][0]].push_back({equations[i][1], values[i]});
            list[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> result;
        for (int i = 0; i < queries.size(); i++)
        {
            string src = queries[i][0], tar = queries[i][1];
            result.push_back(helper(src, tar, visited, list));
        }
        return result;
    }
};