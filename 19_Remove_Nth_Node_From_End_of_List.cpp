/*
Question:
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

*/

//Sol:1 8ms : two pass
/*
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //with Two pointers
        
        ListNode* fast =head;
        ListNode* slow =head;
        
        //Move fast to the end node
        while(n--)
        {
            fast = fast->next;    
        }
        
        if(fast == nullptr)
        {
            return head->next;
        }
        
        while(fast->next != nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        
         slow->next = slow->next->next;
        
        return head;
        
    }
};
*/

//Sol:2 4ms : two pass

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //with Two pointers
        if (head == NULL || n == 0) return head;

        struct ListNode *p0 = head, *p1= head;
        int cnt = 0;
        while (p0->next != NULL) {
            ++cnt;
            p0 = p0->next;
            if (cnt > n)
                p1 = p1->next;
        }

        if (cnt == n - 1) return head->next;

        p1->next = p1->next->next;
        return head;
        
    }
};

//Sol:3 4ms : one pass with queue
/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //with One pointer
        ListNode dummy;
        dummy.next = head;
        ListNode* cur = &dummy;
        queue<ListNode*> q;
        while(cur){
            q.push(cur);
            cur = cur->next;
            while(q.size() > n + 1){
                q.pop();
            }
        }
        ListNode* tmp = q.front(); q.pop();
        ListNode* toRe = q.front(); q.pop();
        tmp->next = toRe->next;
        return dummy.next;
        
    }
};
*/
