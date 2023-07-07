class Solution
{
public:
    void DuplicateInTheInputString(string &str)
    {
        int bitCount = 0;
        for (int i = 0; i < str.size(); i++)
        {
            bitCount |= (1 << (str[i] - 'a'));
        }
        for (int i = 0; i < 26; i++)
        {
            if (bitCount & (i << i))
            {
                cout << i + 'a' << " ";
            }
        }
        cout << "\n";
    }
};