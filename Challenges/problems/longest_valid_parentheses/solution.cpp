// 32. Longest Valid Parentheses
// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

// Example 1:
// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".

// Example 2:
// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".

// Example 3:
// Input: s = ""
// Output: 0

// Constraints:
//     0 <= s.length <= 3 * 104
//     s[i] is '(', or ')'.

// Approach, stack, every succesfully closed adds 2 to the path size,
// if an closing parenthesis appears without an opening, you can consider it to be done for that segment,
// reset, and start over
// Do I need to stack? or can I just count?

// Failed attempt
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int opens{0};
//         int closes{0}; // if closes is more than opens > 1, then we have this ()) , in this case, reset.
//         int longest{0};

//         if (s.length() < 2) // Can't have pair
//         {
//             return 0;
//         }

//         for (auto c : s)
//         {
//             if (c == '(')
//             {
//                 ++opens;
//             } else if (c == ')')
//             {
//                 ++closes;
//             }

//             // Reset
//             if (closes > opens) // closes is at least +1 opens
//             {
//                 int cur = opens * 2;
//                 longest = max(cur, longest);
//                 opens = 0;
//                 closes = 0;
//             }
//         }
//         if (closes == opens) // The last sequency was correct
//         {
//             int cur = opens *2;
//             longest = max(cur, longest);
//         }
//         if (closes < opens && closes != 0) // Remove unclosed ones
//         {
//             opens = (opens - closes);
//             int cur = opens * 2;
//             longest = max(cur, longest);
//         }

//         return longest;
//     }
// };

// Don't work either
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         std::stack<char> open;
//         auto counter{0};
//         auto longest{0};
//         for (auto c : s)
//         {
//             if (c == '(')
//             {
//                 open.push(c);
//             } else if (!open.empty()){ // Still have something inside
//                 open.pop();
//                 counter += 2;
//             } else // Found a closing without opens available
//             {
//                 // Reset
//                 longest = max(longest, counter);
//                 counter = 0;
//             }
//         }

//         longest = max(longest, counter);

//         return longest;
//     }
// };

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Start with a fault
        int maxLen = 0;
        for(int i=0; i<s.length(); i++) {
            char ch = s[i]; // ()()
            if(ch == '(') {
                st.push(i); // [-1, 0] | [-1, 2]
            }
            else {
                st.pop(); // [-1] | [-1]
                if(st.empty()) {
                    st.push(i);
                }
                else {
                    int len = i - st.top(); // 1 - -1 = 2 // 3 - -1 = 4
                    maxLen = max(len, maxLen);
                }
            }
        }
        return maxLen;
    }
};