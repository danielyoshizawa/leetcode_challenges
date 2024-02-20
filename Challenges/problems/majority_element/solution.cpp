// Brute force
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int majority_element_count = nums.size() / 2;
//         // Using hash -> O(n + k)
//         std::map<int,int> occurencies;
//         for (auto n : nums)
//         {
//             ++occurencies[n];
//         }

//         int max{0};
//         int major{0};
//         for (auto o : occurencies)
//         {
//             if (o.second > max)
//             {
//                 max = o.second;
//                 major = o.first;
//             }
//         }
//         return major;
//     }
// };

// Not my solution, got from other users solution, I don't have the users name though, sorry for that!
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int mark = nums[0];
        for(const int& i: nums) {
            if(!count) {
                mark = i; // To replace the marker count must return to zero
                count = 1;
            }
            // This is a competition, who has more occurencies will be able to zero count and conquer it's place as the most frequent element.
            else if(!(mark^i)) // XOR // 1 if both are different
            {
                count++;
            }
            else 
            {
                count--;
            }
        }
        return mark;
    }
};