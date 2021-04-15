/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
    Numbers can have diff sizes
    The number can be zero
    But not 010
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // First I will use brute force for solve this one
        // After I will check if I can make any improviments
        // An try to move to a recursive implementation
        // The sum can be higher than 10, this will move 1 to the next sum
        // [1,2,3,4,5,6,7] + [8,9,8,7,6]
        // [9, 1, 2, 2, 2, 7, 7]
        // [1,2,3,4,5,9,7] + [8,9,8,7,6]
        // [9,1,2,2,2,0,8]
        if (l1 && !l2) {
            return l1;
        }
        if (l2 && !l1) {
            return l2;
        }
        if (!l1 && !l2) {
            return nullptr;
        }
        int sum = l1->val + l2->val;
        if (sum > 9) {
            sum -= 10;
            if (l1->next && l2->next == nullptr) {
                l2->next = new ListNode(1);
            } else if (l2->next && l1->next == nullptr) {
                l1->next = new ListNode(1);
            } else if (l1->next && l2->next) {
                l1->next->val++;
            } else {
                l1->next = new ListNode(1);
            }
        }
        return new ListNode(sum, addTwoNumbers(l1->next, l2->next));
        // result->next = new ListNode(l1->next->val + l2->next->val);
        // result->next->next = new ListNode(l1->next->next->val + l2->next->next->val);
        // return result;
    }
};