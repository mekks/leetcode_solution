/*
Question:
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
 

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.
*/


//Sol:1 16ms
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)return nullptr;
        vector<Node*> nodes;
        map<Node*,Node*> correspondnodes;
        
        Node* origin = head;
        while(origin != nullptr)
        {
            Node* copy =new Node(origin->val);
            nodes.push_back(copy);
            correspondnodes[origin]=copy;
            origin=origin->next;
        }
        
        int len = nodes.size();
        int i = 0;
        origin = head;
        while(origin != nullptr)
        {
            if(i<len-1)nodes[i]->next =nodes[i+1];
            if(origin->random != nullptr)nodes[i]->random = correspondnodes[origin->random];
            i++;
            origin=origin->next;
        }
        return nodes[0];
    }
};
