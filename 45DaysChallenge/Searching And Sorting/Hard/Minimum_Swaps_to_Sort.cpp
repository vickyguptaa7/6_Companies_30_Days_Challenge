/*

The below code is of the graph solutions
ans = Σi = 1k(cycle_size – 1), where k is the number of cycles

Hashmap
While iterating over the array, check the current element, and if not in the correct place, replace that element with the index of the element which should have come to this place greedily which will give the optimal answer
*/

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        vector<pair<int, int>> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());
        int swaps = 0, indx = 0;
        vector<int> visited(nums.size(), 0);
        while (indx < nums.size())
        {
            if (visited[indx])
            {
                indx++;
                continue;
            }
            int src = indx, cycle = 0;
            while (!visited[src])
            {
                visited[src] = true;
                src = temp[src].second;
                cycle++;
            }
            swaps += cycle - 1;
            indx++;
        }
        return swaps;
    }
};