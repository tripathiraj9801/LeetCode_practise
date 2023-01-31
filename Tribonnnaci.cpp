// Problem Link https://leetcode.com/problems/n-th-tribonacci-number/description/

class Solution
{
public:
    int tribonacci(int num)
    {
        int num_1 = 0, num_2 = 1, num_3 = 1, num_n;

        if (num < 2)
            return num;
        else if (num == 2)
            return 1;

        for (int count = 3; count <= num; count++)
        {
            num_n = num_1 + num_2 + num_3;
            num_1 = num_2;
            num_2 = num_3;
            num_3 = num_n;
        }
        return num_n;
    }
};
