// Problem Link https://leetcode.com/problems/3sum/description/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                break;

            if (i > 0 and nums[i] == nums[i - 1])
                continue;

            int j = i + 1, k = n - 1, sum = 0;

            while (j < k)
            {
                sum = nums[i] + nums[j] + nums[k];
                if (sum > 0)
                    k--;
                else if (sum < 0)
                    j++;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int lowestTillnow = nums[j], highestTillnow = nums[k];

                    while (j < k and nums[j] == lowestTillnow)
                        j++;
                    while (j < k and nums[k] == highestTillnow)
                        k--;
                }
            }
        }
        return ans;
    }
};