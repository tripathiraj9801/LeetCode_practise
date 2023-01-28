// Problem Link https://leetcode.com/problems/search-insert-position/description/
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return high + 1;
    }
};

// Solution in Python 3

// class Solution:
//     def searchInsert(self, nums: List[int], target: int) -> int:
//         left, right = 0, len(nums) - 1

//         while left <= right:
//             mid = (left+right)//2
//             if nums[mid] == target:
//                 return mid
//             elif nums[mid] < target:
//                 left = mid + 1
//             elif nums[mid] > target:
//                 right = mid -1

//         return left
