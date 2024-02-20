class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int previous {std::numeric_limits<int>::min()};
        auto it = nums.begin();
        while (it != nums.end())
        {
            if (previous == *it)
            {
                std::rotate(it, it + 1, nums.end()); // Removed from the queue
                nums.pop_back();
            } else {
                previous = *it;
                ++it;
            }
        }

        return nums.size();
    }
};
