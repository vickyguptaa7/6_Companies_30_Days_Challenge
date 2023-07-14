// Given an array which contains integer values, we need to make all values of this array equal to some integer value with minimum cost where the cost of changing an array value x to y is abs(x-y).

/*
This problem can be solved by observing the cost while changing the target equal value, i.e. we will see the change in cost when target equal value is changed. It can be observed that, as we increase the target equal value the total cost decreases up to a limit and then starts increasing i.e. the cost graph with respect to target equal value is of U-shape and as cost graph is in U-shape, the ternary search can be applied to this search space and our goal is to get that bottom most point of the curve which will represent the smallest cost. We will make smallest and largest value of the array as the limit of our search space and then we will keep skipping 1/3 part of the search space until we reach to the bottom most point of our U-curve.

*/

/*
Think geometrically. Assume that array elements are co-ordinates on x axis. The problem reduces to finding another co-ordinate such that the sum of distances between this choice and other co-ordinates is minimized.
Observe that: If number of coordinates are odd then y = middle element. If even then y is any number in between middle 2 co-ordinates. Say Input = [a, b, c, d]. Output is any number between b and c including both. Hence the cost is sum which can be computed easily now that we have chosen y. sum|(y-ai)| for all i.
*/

int findMinimumCost(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int ele = arr[(n) / 2];
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += abs(ele - arr[i]);
    }
    return cost;
}