// Problem Link https://leetcode.com/problems/get-maximum-in-generated-array/description/

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n == 0 || n == 1)
            return n;

        vector<int> vec(n + 1);

        vec[0] = 0;
        vec[1] = 1;

        int maxi = 1;

        for (int i = 2; i <= n; i++)
        {

            if (i % 2 == 0)
            {
                vec[i] = vec[i / 2];
            }
            else
            {
                vec[i] = vec[i / 2] + vec[i / 2 + 1];
            }

            maxi = max(maxi, vec[i]);
        }
        return maxi;
    }
};