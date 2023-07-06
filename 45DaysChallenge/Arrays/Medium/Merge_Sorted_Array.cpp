class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int it1 = m - 1, it2 = n - 1, it3 = n + m - 1;
        while (it1 >= 0 && it2 >= 0)
        {
            if (nums1[it1] < nums2[it2])
            {
                nums1[it3] = nums2[it2];
                it2--;
                it3--;
            }
            else
            {
                nums1[it3] = nums1[it1];
                it1--;
                it3--;
            }
        }
        while (it2 >= 0)
        {
            nums1[it3--] = nums2[it2--];
        }
    }
};