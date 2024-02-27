// 17. Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:
// Input: digits = ""
// Output: []

// Example 3:
// Input: digits = "2"
// Output: ["a","b","c"]

// Constraints:
//     0 <= digits.length <= 4
//     digits[i] is a digit in the range ['2', '9'].


// [2, [a,b,c]]
// [3, [d,e,f]]
// ...
// [9, [w,x,y,z]]

// 2 = a
// 3 = d
// 4 = g
// 5 = j
// 6 = m
// 7 = p
// 8 = t
// 9 = w

class Solution {
public:
    std::map<char, std::vector<char>> letters_map {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y','z'}}
            };

    void backtracking(int i, string digits, string s, vector<string> &ans)
    {
        // Base Case
        if (i == digits.length())
        {
            // Adds the last s to the vector
            if (s.length())
            {
                ans.push_back(s);
            }
            return;
        }

        for (auto c: letters_map[digits[i]])
        {
            backtracking(i + 1, digits, s + c, ans);
        }
    }

    vector<string> letterCombinations(string digits) {

        std::vector<string> ans;
        backtracking(0, digits, "", ans);

        return ans;
    }
};

// Debugging
// bt -> 0 | 23 | ""
// dg[0] -> 2
// lm[2] -> {a,b,c} -> lm[2][0] -> a
// bt -> 1 | 23 | a
// dg[1] -> 3
// lm[3] -> {d,e,f} -> lm[3][0] -> d
// bt -> 2 | 23 | ad
// i == dg.length
// s.length > 0
// ans {ad}
// Returns to the for loop
// dg[1] -> 3
// lm[3] -> {d,e,f} -> lm[3][1] -> e
// bt -> 2 | 23 | ae
// ans {ad, ae}
// Returns to the for loop
// dg[1] -> 3
// lm[3] -> {d,e,f} -> lm[3][2] -> f
// bt -> 2 | 23 | af
// ans {ad, ae, af}
// Ends this bt interaction
// Returns to previous
// dg[0] -> 2
// lm[2] -> {a,b,c} -> lm[2][1] -> b
// bt -> 1 | 23 | b
// dg[1] -> 3
// lm[3] -> {d,e,f} -> lm[3][0] -> d
// bt -> 1 | 23 | bd
// ans{ad,ae,af,bd}
// dg[1] -> 3
// lm[3] -> {d,e,f} -> lm[3][1] -> e
// bt -> 1 | 23 | be
// ans{ad,ae,af,bd,be}
// dg[1] -> 3
// lm[3] -> {d,e,f} -> lm[3][2] -> f
// bt -> 1 | 23 | bf
// ans{ad,ae,af,bd,be,bf}
// Return to previous
// dg[0] -> 2
// lm[2] -> {a,b,c} -> lm[2][2] -> c
// bt -> 1 | 23 | c
// dg[1] -> 3
// lm[3] -> {d,e,f} -> lm[3][0] -> d
// bt -> 1 | 23 | cd
// ans{ad,ae,af,bd,be,bf,cd}
// dg[1] -> 3
// lm[3] -> {d,e,f} -> lm[3][1] -> e
// bt -> 1 | 23 | ce
// ans{ad,ae,af,bd,be,bf,cd,ce}
// dg[1] -> 3
// lm[3] -> {d,e,f} -> lm[3][2] -> f
// bt -> 1 | 23 | cf
// ans{ad,ae,af,bd,be,bf,cd,ce,cf}
// Ends execution