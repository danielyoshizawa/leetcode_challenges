// O(N^2)
// 1,2,3,0,0,0 -> 2,5,6
// n : 2
// 1 < 2 -> next
// 2 == 2 -> insert [1,2,2,3,0,0]
// n : 5 
// 1 < 5 -> next
// 2 < 5 -> next
// 2 < 5 -> next
// 2 < 3 -> next
// size limit m = 4 [New size]
// insert 5 -> [1,2,2,3,5,0]
// n : 6
// 1 < 6
// 2 < 6
// 2 < 6
// 3 < 6
// 5 < 6
// size limit m = 5
// insert 6 -> [1,2,2,3,5,6]

// 1,2,3,0,0,0 -> 2,5,6
// concat -> How much it costs? I thing O(1)
// 1,2,3,2,5,6
// Merge sort -> O(nlog(N))
// 1,2,3 -> 2,5,6 -- Split again
// 1,2 -> 3 | 2,5 -> 6
// 1 -> 2 | 3 | 2 -> 5 | 6 -- Final
// [1,2] | [3] | [2,5] | [6]
// [1,2,3] | [2,5,6] -> We only need this step
// [1,2,2,3,5,6]

// 1,2,3,0,0,0 -> 2,5,6
// n : 2
// 1 < 2
// 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        // int left_pos {0};
        // int right_pos {0};
        // vector<int> tmp{m + n}; // TODO : Operate on nums1

        // while (left_pos < m && right_pos < n)
        // {
        //     if (nums1[left_pos] <= nums2[right_pos])
        //     {
        //         tmp.push_back(nums1[left_pos]); // TODO : Use emplace
        //         ++left_pos;
        //     } else {
        //         tmp.push_back(nums2[right_pos]);
        //         ++right_pos;
        //     }
        // }

        // // Meaning that are elements left in the nums1
        // for (int i{left_pos}; i < m; ++i)
        // {
        //     tmp.push_back(nums1[i]); // TODO : Remove
        // }
        // for (int i{right_pos}; i < n; ++i)
        // {
        //     tmp.push_back(nums2[i]); // TODO : Use range
        // }

        // nums1 = tmp;

        // Optimization
        auto left_it {std::begin(nums1)};
        auto right_it {std::begin(nums2)};
        int count {1};
// 0 | 1
// [1,0] | [2]
// [1,2,3,0,0,0] | [2,5,6]
// 1 -> 2 [1,] count = 1
// 2 -> 2 [1,2] count = 2
// 3 -> 2 [1,2,2,] 
// 3 -> 5 [1,2,2,3,] count = 3 > 3
// 0 -> 5 [1,2,2,3,0] count = 4
// 0 -> 5 [1.2,2,3,0,5]
// 5 -> [1,2,2,3,5]
// 6 -> [1,2,2,3,5,6]
        while (left_it != std::end(nums1) && right_it != std::end(nums2))
        {
            // Multiple If Else clauses is a performance enhancement on this platform, this is new to me
            if (m == 0 )
            {
                left_it = nums1.emplace(left_it, *right_it); // Need to remove the zeros // Everytime I emplace I need to remove the last element
                nums1.pop_back(); // Removes the last element
                ++right_it;
                ++left_it; // Re position the letf_it to the correct element
            } else
            if (count > m)
            {
                left_it = nums1.emplace(left_it, *right_it); // Need to remove the zeros // Everytime I emplace I need to remove the last element
                nums1.pop_back(); // Removes the last element
                ++right_it;
                ++left_it; // Re position the letf_it to the correct element
            } else
            if ( *left_it > *right_it) // Insert Right
            {
                left_it = nums1.emplace(left_it, *right_it); // Need to remove the zeros // Everytime I emplace I need to remove the last element
                nums1.pop_back(); // Removes the last element
                ++right_it;
                ++left_it; // Re position the letf_it to the correct element
            } else {
                ++left_it;
                ++count;
            }
        }
    }
};