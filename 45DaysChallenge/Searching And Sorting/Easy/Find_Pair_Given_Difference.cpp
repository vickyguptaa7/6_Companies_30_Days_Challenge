bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    int left = 0, right = 1;
    while (left < size && right < size)
    {
        if (arr[right] - arr[left] == n && left != right)
        {
            return true;
        }
        else if (arr[right] - arr[left] > n)
        {
            left++;
        }
        else
        {
            right++;
        }
    }
    return 0;
}