int findCeil(int arr[], int n, int x)
{
    int l = 0, h = n - 1, val = -1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] >= x)
        {
            val = arr[mid];
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return val;
}

int findFloor(int arr[], int n, int x)
{
    int l = 0, h = n - 1, val = -1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] <= x)
        {
            val = arr[mid];
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return val;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    sort(arr, arr + n);
    return {findFloor(arr, n, x), findCeil(arr, n, x)};
}