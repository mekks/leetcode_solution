/*
Question:
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

//Sol:1 4ms
/*
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
    TreeNode* invertTree(TreeNode* root) {
       //Level order Treversal with queue
        if(!root)return NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            swap(node->left , node->right);
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        return root;
    }
};
*/

//Sol:2 4ms
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)return NULL;
        
        TreeNode* r=invertTree(root->right);
        TreeNode* l=invertTree(root->left);
        
        root->left=r;
        root->right=l;
        return root;
    }
};
