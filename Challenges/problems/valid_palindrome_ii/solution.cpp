// 680. Valid Palindrome II

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:
// Input: s = "aba"
// Output: true

// Example 2:
// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:
// Input: s = "abc"
// Output: false

// Constraints:
//     1 <= s.length <= 105
//     s consists of lowercase English letters.

// aba
// 1. a 2. a
// a == a -> next
// 1. b 2.b
// b == b -> next
// return true

// abca
// 1. a 2. a
// a == a -> next
// 1.b 2.c
// b != c -> I need to choose which letter I will delete (deleting c)
// 1.b 2.b
// b == b -> works
// 1.c 2.c
// c == c -> works

// abc
// 1. a 2.c
// a != c -> Delete what?
// 1.a 2.b
// a != b
// 1.b 2.c
// b != c -> Works

// Now hear me out
// racecdar
// 1.r 2.r
// 1.a 2.a
// 1.c 2.d -> Need to check the next for both, and follow the equal path

class Solution {
public:
    bool validPalindrome(string s) {
        // two pointer solution
        int i = 0;
        int j = s.length() - 1;
        if (!isPalindrome(s, i, j))
        {
            int i2 = i;
            int j2 = j;
            return isPalindrome(s, ++i, j) || isPalindrome(s, i2, --j2);
        } 
        return true;
    }
    bool isPalindrome(const string & s, int & i, int & j)
    {
        while(i <= j) {
            // std::cout << i << ":" << s[i] << " | " << j << ":" << s[j] << std::endl;
            if (s[i] == s[j])
            {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};