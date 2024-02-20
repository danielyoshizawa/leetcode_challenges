class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Iterate over the vector remove the elements that are equal to val
        // We could improve it by moving than to the end, need to check which function is less complex
        // Iterate and swap with the next element that is not equal to val
        // [1,2,3,4,5,6] val = 3
        // [1,2,4,3,5,6] val = 3
        // [1,2,4,5,3,6]
        // [1,2,4,5,6,3]

        // [1,2,3,4,5,3,6,7]
        // [1,2,4,3,5,3,6,7]
        // [1,2,4,5,3,3,6,7]
        // [1,2,4,5,3,3,6,7]
        // [1,2,4,5,3,6,3,7]
        // [1,2,4,5,3,6,7,3]
        // [1,2,4,5,6,3,7,3]
        // [1,2,4,5,6,7,3,3]

        // Reverse approach (iterate in rever order and move element to the end)
        // [2,3,5,6]
        // [2,5,6,3]

        // [2,3,4,*3,5,6] find 3
        // [2,3,4,5,6,3] find 3
        // [2,4,5,6,3,3]
        // int count{0};
        // for (auto it = std::begin(nums); it != std::end(nums);) // O(N^2)
        // {
        //     if (*it == val) // Move to the end
        //     {
        //         it = nums.erase(it); // Remove it, we don't care // Linear
        //     } else {
        //         ++it;
        //         ++count;
        //     }
        // }
        // return count;

        // Optimization
        // Need to define the next equal to
        // Remove and get the iterator
        auto it = nums.begin();
        while(it != nums.end()) // Find the last of val
        {
            it = std::find(it, nums.end(), val); // Check complexity
            if (it != nums.end())
            {
                it = nums.erase(it); // Not good enough
            }
        }

        return nums.size();
    }
};