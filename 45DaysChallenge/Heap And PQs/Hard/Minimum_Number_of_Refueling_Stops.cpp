class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {

        if (startFuel >= target)
            return 0;

        priority_queue<int> pque;
        int indx = 0, n = stations.size();
        while (indx < n && startFuel >= stations[indx][0])
            pque.push(stations[indx++][1]);

        int stops = 0;

        while (!pque.empty())
        {
            startFuel += pque.top();
            pque.pop();
            stops++;
            if (startFuel >= target)
                return stops;
            while (indx < n && startFuel >= stations[indx][0])
                pque.push(stations[indx++][1]);
        }

        return -1;
    }
};