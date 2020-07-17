/*
Question:

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

//Sol:1 28ms recursive
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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        queue<int> inorder;
        
        dfs(root, inorder);
        
        int former = inorder.front(); 
        inorder.pop();
        
        while(!inorder.empty()){
            if(former >= inorder.front()) return false;
            //check it from right side nodes 
            former = inorder.front();
            inorder.pop();
        }
        
        return true;
    }
    
    void dfs(TreeNode* root, queue<int>& que){
        if(root == NULL) return;
        
        dfs(root->left, que);
        que.push(root->val);   
        dfs(root->right, que);
    } 
    
};
*/

//Sol:2 24ms recursive
/*
class Solution {
public:
   bool isValidBST(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX) {
	if(!root) return true;
	if(root->val <= min || root->val >= max) return false;
	return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
}
};
*/

//Sol:3 16ms
class Solution {
public:
    vector<int> inorder;//store the inorder
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        inOrder(root);
        for (size_t i = 0; i < inorder.size() - 1; i++) {
            if (inorder[i] >= inorder[i + 1]) return false;
        }
        return true;
    }
    
    void inOrder(TreeNode* root) {
        if (!root) return ;
        inOrder(root->left);
        this->inorder.push_back(root->val);
        inOrder(root->right);
    }
    
};
