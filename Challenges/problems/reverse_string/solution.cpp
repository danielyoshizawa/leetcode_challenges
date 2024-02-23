// 344. Reverse String

// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

// Example 2:
// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]

// Constraints:
//     1 <= s.length <= 105
//     s[i] is a printable ascii character.

// Straight to the point
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         std::reverse(s.begin(), s.end()); // std::distance(first,last) / 2 swaps
//     }
// };

// // Implementing the algorithm using additional variable
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int end = s.size() - 1;

//         for (int i{0}; i < (s.size() / 2); ++i) // complexity O (N/2) - Same as above
//         {
//             auto tmp = s[end - i]; // Lets remove this
//             s[end - i] = s[i];
//             s[i] = tmp;
//         }
//     }
// };

// Implementing the algorithm without using additional variable
class Solution {
public:
    void reverseString(vector<char>& s) {
        int end = s.size() - 1;

        for (int i{0}; i < (s.size() / 2); ++i) // complexity O (N/2) - Same as above
        {
            if (s[i] > s[end - i]) // a > b
            {
                s[i] = s[i] + s[end - i];
                s[end-i] = s[i] - s[end-i];
                s[i] = s[i] - s[end - i];
            } else if (s[i] < s[end -i]) // a < b
            {
                s[end - i] = s[i] + s[end - i];
                s[i] = s[end -i] - s[i];
                s[end - i] = s[end -i] - s[i];
            }
        }
    }
};
