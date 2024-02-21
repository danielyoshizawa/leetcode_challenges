// 125. Valid Palindrome

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

// Example 3:
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

// Constraints:
//     1 <= s.length <= 2 * 105
//     s consists only of printable ASCII characters.

#include <cctype>
#include <array>

bool isInvalid(char & c) // Should have a single responsibility, but for performance we will ignore it
{
    c = std::tolower(c); // Not a good design choice, however will improve performance
    return !static_cast<bool>(std::isalnum(c));
}

class Solution {
private:
    void treat(string &s)
    {
        s.erase(std::remove_if(s.begin(), s.end(), isInvalid), s.end());
    }
public:
    bool isPalindrome(string s) {
        treat(s);
        std::cout << s << std::endl;
        auto it_reverse = s.rbegin();
        auto is{true};

        for (auto c : s)
        {
            if (c == *it_reverse)
            {
                ++it_reverse;
                continue;
            } else
            {
                is = false;
                break;
            }
        }

        return is;
    }
};