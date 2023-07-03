class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        set<string> dictBank;
        for (auto x : bank)
            dictBank.insert(x);
        queue<string> que;
        que.push(startGene);
        if (dictBank.count(startGene))
            dictBank.erase(startGene);
        int mutations = 0;
        vector<char> charac = {'A',
                               'C',
                               'T',
                               'G'};
        while (!que.empty())
        {
            int size = que.size();
            while (size--)
            {
                string curr = que.front();
                que.pop();
                if (curr == endGene)
                    return mutations;
                for (int i = 0; i < curr.size(); i++)
                {
                    char prev = curr[i];
                    for (int j = 0; j < 4; j++)
                    {
                        if (charac[j] == prev)
                            continue;
                        curr[i] = charac[j];
                        if (dictBank.count(curr))
                        {
                            que.push(curr);
                            dictBank.erase(curr);
                        }
                    }
                    curr[i] = prev;
                }
            }
            mutations++;
        }
        return -1;
    }
};