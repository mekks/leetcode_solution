/*
Question:
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

//Sol:1 76ms
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
    ListNode* sortList(ListNode* head) {
        vector<int> result;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        while(head != nullptr){
            result.push_back(head->val);
            head = head->next;
        }
        sort(result.begin(),result.end());
        ListNode* ptr = dummy->next;
        for(int& i:result){
            ptr->val = i;
            ptr = ptr->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
*/

//Sol:2 72ms

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode* slow = head , *fast=head->next;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        return mergeList(sortList(head) , sortList(fast));
    }
    ListNode* mergeList(ListNode* p1 , ListNode* p2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* current=dummy;
        while(p1 && p2)
        {
            if(p1->val < p2->val)
            {
                current->next = p1;
                p1=p1->next;
            }
            else
            {
                current->next = p2;
                p2 = p2->next;
            }
            current = current->next;
        }
        if(p1)
        {
            current->next = p1;
        }
        else
        {
            current->next = p2;
        }
        current=dummy->next;
        delete dummy;
        return current;
    }
};
