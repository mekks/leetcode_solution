/*
Question:
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/

//Sol:1 4ms 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* temp =root;
        stack<TreeNode*> sta;
        if(!root)
            return;
        if(root->right != NULL ||  root->left != NULL)
        { 
            sta.push(temp->right);
            sta.push(temp->left);   
        }
        while(!sta.empty())
        {
            TreeNode* curr = sta.top();
            sta.pop();
            if(curr == nullptr) continue;
            temp->left = NULL;
            temp->right = curr;
            sta.push(curr->right);
            sta.push(curr->left);
            temp=temp->right;
        }
    }
};
