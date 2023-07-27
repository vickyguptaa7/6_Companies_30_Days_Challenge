class Solution
{
public:
    int helper(Node *root, int k, unordered_map<long long, int> &freq, long long currSum)
    {
        if (!root)
            return 0;

        long long paths = 0, mod = 1e9 + 7;
        currSum += root->data;

        if (freq.count(currSum - k))
            paths += freq[currSum - k];

        freq[currSum]++;

        paths += helper(root->left, k, freq, currSum);
        paths += helper(root->right, k, freq, currSum);

        freq[currSum]--;
        return paths % mod;
    }

    int sumK(Node *root, int k)
    {
        unordered_map<long long, int> freq;
        freq[0]++;
        return helper(root, k, freq, 0);
    }
};