// Problem Link https://leetcode.com/problems/first-missing-positive/description/

// Can also be done using recursive binary search but it will take much runtime than any other solution.

// Using Hashmap to solve it in O(n) time and auxilary n space.
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> freq;
        int maxi = *max_element(nums.begin(), nums.end());

        for (auto x : nums)
            freq[x]++;
        if (maxi < 0)
            return 1;

        for (int i = 1; i < maxi; ++i)
        {
            if (freq[i] == 0)
                return i;
        }
        return maxi + 1;
    }
};