class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        int amount = 0, prev = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            amount += (p[i % n].petrol - p[i % n].distance);
            while (amount < 0)
            {
                amount -= (p[prev % n].petrol - p[prev % n].distance);
                prev++;
            }
            if (i - prev + 1 == n)
                return prev;
        }
        return -1;
    }
};