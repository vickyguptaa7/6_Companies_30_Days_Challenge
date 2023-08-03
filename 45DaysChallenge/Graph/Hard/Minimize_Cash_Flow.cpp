class Solution
{
public:
    vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n)
    {
        vector<int> netAmount(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                netAmount[i] -= transaction[i][j];
                netAmount[j] += transaction[i][j];
            }
        }
        multiset<pair<int, int>> balance;
        for (int i = 0; i < n; i++)
        {
            if (netAmount[i])
                balance.insert({netAmount[i], i});
        }
        vector<vector<int>> minCash(n, vector<int>(n, 0));
        while (!balance.empty())
        {
            int reciever = balance.rbegin()->second;
            int payer = balance.begin()->second;
            int ramount = balance.rbegin()->first;
            int pamount = balance.begin()->first;
            // cout<<reciever<<" "<<payer<<'\n';
            // cout<<ramount<<" "<<pamount<<'\n';
            // cout<<"\n";
            balance.erase(balance.begin());
            balance.erase(prev(balance.end()));
            int amount = min(ramount, abs(pamount));
            pamount += amount;
            ramount -= amount;
            minCash[payer][reciever] += amount;
            if (pamount)
            {
                balance.insert({pamount, payer});
            }
            if (ramount)
            {
                balance.insert({ramount, reciever});
            }
        }
        return minCash;
    }
};