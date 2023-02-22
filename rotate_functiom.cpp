// Problem Link https://leetcode.com/problems/rotate-function/

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int ans = INT_MIN;
        int n = nums.size();
        int sum = 0;
        int sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            sum2 += nums[i] * i;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            sum2 = sum2 - (nums[i] * (n - 1)) + (sum - nums[i]);
            ans = max(ans, sum2);
        }
        return ans;
    }
};

// Alternate Solution

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int size = nums.size();
        int original_sum = 0, array_sum = 0;
        for (int i = 0; i < size; i++)
        {
            array_sum += nums[i];
            original_sum += i * nums[i];
        }
        int ans = original_sum;
        for (int i = 0; i < size; i++)
        {
            original_sum += array_sum - (size * nums[size - i - 1]);
            ans = max(ans, original_sum);
        }
        return ans;
    }
};