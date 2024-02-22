// 1838. Frequency of the Most Frequent Element

// The frequency of an element is the number of times it occurs in an array.

// You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

// Return the maximum possible frequency of an element after performing at most k operations.

// Example 1:
// Input: nums = [1,2,4], k = 5
// Output: 3
// Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
// 4 has a frequency of 3.

// Example 2:
// Input: nums = [1,4,8,13], k = 5
// Output: 2
// Explanation: There are multiple optimal solutions:
// - Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
// - Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
// - Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.

// Example 3:
// Input: nums = [3,9,6], k = 2
// Output: 1

// Constraints:
//     1 <= nums.length <= 105
//     1 <= nums[i] <= 105
//     1aa <= k <= 105

// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) 
//     {
//         // Brute Force
//         if (nums.size() <= 1) // 0 or 1 element
//         {
//             return nums.size();
//         }

//         auto most_frequent{0};
//         for (auto it = nums.begin(); it != nums.end(); ++it) // O(N^2)
//         {
//             auto left {k};
//             auto frequency{0};
//             for(auto it2 = nums.begin(); it2 != nums.end(); ++it2)
//             {
//                 if (*it < *it2)
//                 {
//                     continue;
//                 }
//                 else if (*it == *it2) // Same add to frequency without change
//                 {
//                     ++frequency;
//                 } else if (*it <= *it2 + left)
//                 {
//                     left -= (*it - *it2);
//                     ++frequency;
//                 }
//             }
//             most_frequent = max(most_frequent, frequency);
//         }

//         return most_frequent;
//     }
// };


// Approach 2 - from the editorial
// 
// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) 
//     {
//         if (nums.size() <= 1) // 0 or 1 element
//         {
//             return nums.size();
//         }

//         std::sort(nums.begin(), nums.end()); // O (nlogn)
//         long left{0},right{0}, ans{0}, curr{0};

//         for(; right < nums.size(); ++right) // O(N)
//         {
//             auto target = nums[right];
//             curr += target;
//             while (((right-left+1)*target - curr) > k) // Amortized O(1)
//             {
//                 curr -= nums[left];
//                 ++left;
//             }
//             ans = max(ans, (right-left+1));
//         }

//         return ans;
//     }

// };

// Improvement over the last solution
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        if (nums.size() <= 1) // 0 or 1 element
        {
            return nums.size();
        }

        std::sort(nums.begin(), nums.end()); // O (nlogn)
        long left{0},right{0}, curr{0};

        for(; right < nums.size(); ++right) // O(N)
        {
            auto target = nums[right];
            curr += target;
            if (((right-left+1)*target - curr) > k) // We don't need to calc every window size
            {
                curr -= nums[left];
                ++left;
            }
        }

        return nums.size() - left;
    }

};