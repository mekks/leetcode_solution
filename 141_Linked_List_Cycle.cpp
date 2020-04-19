/*
Question:
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

*/
//Solution_1
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
    ListNode* reverseList(ListNode* head) 
    {
	    ListNode* prev = NULL;
	    ListNode* follow = NULL;
	    while (head)
	    {
		    follow = head->next;
		    head->next = prev;
		    prev = head;
		    head = follow;
	    }
    return prev;
    }
    bool hasCycle(ListNode *head) {
        ListNode* rev = reverseList(head);
	    if (head && head->next && rev == head)
	    {
	    	return true;
	    }
	return false;
    }
};

//Solution_2
/*

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode *fast, *slow;
       fast = slow = head;
        while (fast && fast->next) 
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                return true;
        }
    return false; 
    }
};
*/
