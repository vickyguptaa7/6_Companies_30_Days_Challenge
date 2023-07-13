/*
// Time Complexity O(nlogn)
The idea is to compare the given array with its sorted version. Make a copy of the given array and sort it. Now, find the first index and last index in the given array which does not match with the sorted array. If no such indices are found (given array was already sorted), return True. Else check if the elements between the found indices are in decreasing order, if Yes then return True else return False

// Time Complexity O(n)
Initialize two variables x and y with -1.
Iterate over the array.
    Find the first number for which a[i] > a[i+1] and store it into x.
    Similarly, Store index i+1 as well into y, As this will keep track of the ending of the subarray which is needed to reverse.
Check if x == -1 then array is already sorted so return true.
Otherwise, reverse the array from index x to index y.
    Traverse the array to check for every element is sorted or not.
        If not sorted, return false.
Finally, return true.
*/

bool sortArr(int a[], int n)
{
    int x = -1;
    int y = -1;

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            if (x == -1)
            {
                x = i;
            }
            y = i + 1;
        }
    }

    if (x == -1)
        return true;

    reverse(a + x, a + y + 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return false;
        }
    }

    return true;
}