class Solution
{
public:
    string intToRoman(int num)
    {
        vector<int> nums = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> romans = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD",
                                 "D", "CM", "M"};
        string roman = "";
        int indx = (int)nums.size() - 1;
        while (num && indx >= 0)
        {
            if (num >= nums[indx])
            {
                num -= nums[indx];
                roman += romans[indx];
            }
            else
            {
                indx--;
            }
        }
        return roman;
    }
};