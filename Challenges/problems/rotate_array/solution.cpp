// Mine solution, ran in 19ms
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         // Loop is mandatory
//         if (k > nums.size())
//         {
//             for (int i{k}; i > 0; --i)
//             {
//             std::rotate(nums.rbegin(), nums.rbegin() + 1, nums.rend());
//             }
//         } else {
//             std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend()); // Only need to run once
//         }
//     }
// };

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1); // Revert the whole vector
    reverse(nums, 0, k - 1); // Revert the new start fo the vector
    reverse(nums, k, nums.size() - 1); // revert the new last of the vector
  }

 private:
  void reverse(vector<int>& nums, int l, int r) {
    while (l < r)
      swap(nums[l++], nums[r--]); // How this performs better than rotate?
  }
};