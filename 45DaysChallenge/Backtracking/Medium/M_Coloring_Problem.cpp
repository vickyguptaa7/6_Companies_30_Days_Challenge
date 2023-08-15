class Solution
{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.

    bool isSafe(int src, int n, int m, vector<int> &colour, bool graph[101][101])
    {
        for (int i = 0; i < n; i++)
        {
            if (src != i && graph[src][i] && colour[src] == colour[i])
                return false;
        }
        return true;
    }

    bool helper(int src, int n, int m, vector<int> &color, bool graph[101][101])
    {
        if (src == n)
            return true;
        for (int i = 1; i <= m; i++)
        {
            color[src] = i;
            if (isSafe(src, n, m, color, graph) && helper(src + 1, n, m, color, graph))
            {
                return true;
            }
            color[src] = 0;
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<int> color(n, 0);
        return helper(0, n, m, color, graph);
    }
};