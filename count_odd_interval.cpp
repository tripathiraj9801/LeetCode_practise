// Problem Link https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int n = high - low + 1;
        if (low % 2 == 1 and high % 2 == 1)
        {
            int odds = n / 2 + 1;
            return odds;
        }
        else
        {
            int odds = n / 2;
            return odds;
        }
        return 0;
    }
};