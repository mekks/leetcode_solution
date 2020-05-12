/*
Question:
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

*/

//Sol _1 28ms
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       stack<ListNode*> nodeStack; 
		
        ListNode* pHead = head;
        while (pHead) {
            nodeStack.push(pHead);
            pHead = pHead->next;
        }
        
        while (head) {
            if (head->val != nodeStack.top()->val) 
            { 
                return false;  
            }
            nodeStack.pop(); 
            head = head->next;
        }
        return true;
    }
};
