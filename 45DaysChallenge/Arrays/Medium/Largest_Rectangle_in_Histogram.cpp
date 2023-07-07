class Solution
{
public:
    vector<int> findNextSmallestToLeft(vector<int> &heights)
    {
        vector<int> nextSmallRight;
        int size = heights.size();
        stack<int> st;
        for (int i = 0; i < size; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
                nextSmallRight.push_back(-1);
            else
                nextSmallRight.push_back(st.top());
            st.push(i);
        }
        return nextSmallRight;
    }
    vector<int> findNextSmallestToRight(vector<int> &heights)
    {
        vector<int> nextSmallLeft;
        int size = heights.size();
        stack<int> st;
        for (int i = size - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
                nextSmallLeft.push_back(size);
            else
                nextSmallLeft.push_back(st.top());
            st.push(i);
        }
        reverse(nextSmallLeft.begin(), nextSmallLeft.end());
        return nextSmallLeft;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> nextSmallRight = findNextSmallestToRight(heights);
        vector<int> nextSmallLeft = findNextSmallestToLeft(heights);
        int mxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            mxArea = max(mxArea, heights[i] * (nextSmallRight[i] - nextSmallLeft[i] - 1));
        }
        return mxArea;
    }
};