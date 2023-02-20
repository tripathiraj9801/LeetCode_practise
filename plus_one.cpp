// Problem Link https://leetcode.com/problems/plus-one/description/

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carr = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int sum = carr + digits[i];
            digits[i] = sum % 10;
            carr = sum / 10;
        }

        if (carr)
            digits.insert(digits.begin(), carr);

        return digits;
    }
};