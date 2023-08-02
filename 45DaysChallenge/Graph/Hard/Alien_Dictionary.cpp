class Solution
{

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> list[26];
        for (int i = 1; i < N; i++)
        {
            int len = min(dict[i].size(), dict[i - 1].size());
            for (int j = 0; j < len; j++)
            {
                if (dict[i - 1][j] == dict[i][j])
                    continue;
                list[dict[i - 1][j] - 'a'].push_back(dict[i][j] - 'a');
                break;
            }
        }
        vector<int> inorder(26, 0);
        for (int i = 0; i < 26; i++)
        {
            for (auto child : list[i])
            {
                inorder[child]++;
            }
        }
        queue<int> que;
        string result;
        for (int i = 0; i < 26; i++)
        {
            if (!inorder[i])
                que.push(i);
        }
        while (!que.empty())
        {
            int curr = que.front();
            que.pop();
            result += char(curr + 'a');
            K--;
            for (auto child : list[curr])
            {
                inorder[child]--;
                if (!inorder[child])
                    que.push(child);
            }
        }
        return result;
    }
};