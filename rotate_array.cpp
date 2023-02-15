// Problem Link https://leetcode.com/problems/rotate-array/description/
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size();
        k = k % size;
        reverse(begin(nums), end(nums));
        reverse(begin(nums), begin(nums) + k);
        reverse(begin(nums) + k, end(nums));
    }
};