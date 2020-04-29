/*
Question:
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both

//Sol:1 12ms
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
      ListNode* helper(ListNode* head, ListNode* prev) {
        if (!head) return prev;
        ListNode* next = head->next;
        head->next = prev;
        return helper(next, head);
      
        
    }
    
    ListNode* reverseList(ListNode* head) {       
        return helper (head, NULL);
        
    }
};

Sol:2 16ms
/**
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if (!head || !(head -> next)) {
            return head;
        }
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
    }
};
*/
//Sol:3 8ms

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* q = NULL;
        ListNode* r = NULL;

        while (head != NULL) {
            r = q;
            q = head;
            head = head->next;
            q->next = r;
        }

        head = q;
        return head;
    }
};
