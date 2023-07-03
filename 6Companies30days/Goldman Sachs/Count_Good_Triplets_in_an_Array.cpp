/* _______________Policy Based DS______________*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// provides find_by_order, order_of_key
/*_____________________________________________*/

class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> indx(n, 0);
        for (int i = 0; i < n; i++)
        {
            indx[nums2[i]] = i;
        }
        vector<int> prefixIntersect(n, 0), suffixIntersect(n, 0);
        ordered_set<int> preSet, suffSet;
        for (int i = 0; i < n; i++)
        {
            prefixIntersect[i] = preSet.order_of_key(indx[nums1[i]]);
            preSet.insert(indx[nums1[i]]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            suffixIntersect[i] = suffSet.order_of_key(-indx[nums1[i]]);
            suffSet.insert(-indx[nums1[i]]);
        }
        long long result = 0;
        for (int i = 0; i < n; i++)
        {
            result += (long long)prefixIntersect[i] * suffixIntersect[i];
        }
        return result;
    }
};
/*

We iterate on every element of first array and find its occurance in the second array lets say that is j. now our answer contribute by this element would be :-
Number of overlapping elements in n1 from 0 to i and in n2 from 0 to j. lets say this is pref[i]
and multiply this with number of overlapping elements in n1 from i + 1 to n and in n2 from j + 1 to n lets say this suff[i]

How to get number of elements strictly greater ?
Well, there is a trick insert all elements as -ve now call order of key for negative it will automatically give number of elements greater than my current number.
*/