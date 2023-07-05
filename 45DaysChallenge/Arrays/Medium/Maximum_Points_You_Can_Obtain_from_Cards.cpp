class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int wsize = n - k;
        int sum = 0, total = accumulate(cardPoints.begin(), cardPoints.end(), 0ll);
        for (int i = 0; i < wsize; i++)
            sum += cardPoints[i];
        int result = total - sum;
        for (int i = wsize; i < n; i++)
        {
            sum += cardPoints[i];
            sum -= cardPoints[i - wsize];
            result = max(result, total - sum);
        }
        return result;
    }
};