class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int N, vector<int> list[])
    {
        queue<int> que;
        vector<int> inorder(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < list[i].size(); j++)
            {
                inorder[list[i][j]]++;
            }
        }
        vector<int> topo;
        for (int i = 0; i < N; i++)
        {
            if (inorder[i] == 0)
            {
                que.push(i);
            }
        }
        while (!que.empty())
        {
            int curr = que.front();
            topo.push_back(curr);
            que.pop();
            for (auto child : list[curr])
            {
                inorder[child]--;
                if (inorder[child] != 0)
                    continue;
                que.push(child);
            }
        }
        return topo;
    }
};