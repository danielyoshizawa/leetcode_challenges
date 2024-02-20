class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int previous {std::numeric_limits<int>::min()};
        auto it = nums.begin();
        int previous_count{0};

        while (it != nums.end())
        {
            if (previous == *it)
            {
                if (previous_count == 1) {
                    std::rotate(it, it + 1, nums.end()); // Removed from the queue
                    nums.pop_back();
                } else {
                    ++previous_count;
                    ++it;
                }
            } else {
                 // Added to the queue // Problems, double rotation // Last Element
                previous_count = 0;
                previous = *it;
                ++it;
            }
        }

        return nums.size();
    }
};