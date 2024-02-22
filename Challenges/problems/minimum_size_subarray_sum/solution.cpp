// 209. Minimum Size Subarray Sum

// Given an array of positive integers nums and a positive integer target, return the minimal length of a
// subarray
// whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// Example 1:
// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Example 2:
// Input: target = 4, nums = [1,4,4]
// Output: 1

// Example 3:
// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

// Constraints:
//     1 <= target <= 109
//     1 <= nums.length <= 105
//     1 <= nums[i] <= 104

// Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = std::numeric_limits<int>::max();
        std::vector<int> sums(n+1,0);
        // Accumulate the sum of elements
        for (int i{1}; i <= n; ++i)
        {
            sums[i] = sums[i -1] + nums[i - 1];
        }

        for (int i = 1; i <= n; ++i) // O(N)
        {
            int to_find = target + sums[i - 1]; // To move to the next index we need to sum the previous value OR remove the previous value from the target SUM

            auto bound = lower_bound(sums.begin(), sums.end(), to_find); // O(log N)
            if (bound != sums.end())
            {
                ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1))); // Vector distance between bound and sum.begin + i - 1
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};