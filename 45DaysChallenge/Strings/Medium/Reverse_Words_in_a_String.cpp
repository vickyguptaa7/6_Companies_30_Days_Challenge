class Solution
{
public:
    void removeExtraSpace(string &s)
    {
        int prev = 0;
        int indx = 0;
        while (s[indx] == ' ')
            indx++;
        for (int i = indx; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                while (i < s.size() && s[i] == ' ')
                    i++;
                i--;
            }
            s[prev++] = s[i];
        }
        s.resize(prev);
        if (s.back() == ' ')
            s.pop_back();
    }

    string reverseWords(string s)
    {
        removeExtraSpace(s);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            int next = i, prev = i;
            while (next + 1 < s.size() && s[next + 1] != ' ')
                next++;
            i = next;
            while (prev < next)
            {
                swap(s[prev], s[next]);
                next--;
                prev++;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};