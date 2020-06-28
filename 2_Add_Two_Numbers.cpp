/*
Question:
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

//Sol:1 
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        int carry = 0;
        while (l1 || l2 || carry) {
            int num = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = num / 10;
            cur->next = new ListNode(num % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head->next;
    }
};
*/
//Sol:2 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int former = 0;
        ListNode* head = l1;
         while(l1) {
             former += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
             l1->val = former % 10;
             former/=10;
             if(!l1->next && l2 && l2->next) {
                 // if l1 ends but l2 doesn't, we point l1->next to l2->next
                 l1->next = l2->next;
                 l2 = NULL;
             }
             else if(!l1->next && !(l2&&l2->next) && former) {
                 // if l1 & l2 both end, we make a new node (assign to l1->next)
                 l1->next = new ListNode(0);
                 l2 = NULL;
             }
             if(l2) l2 = l2->next;
             l1 = l1->next;
         }
        return head;
    }
};
