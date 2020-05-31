/*
Question:

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

*/
//Sol_1 preorder traversal 32ms
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
    int val;
    int ans;
    void fun(TreeNode *root)
    {
        if(root==NULL)
            return ;
        fun(root->left);
        val--;
        if(val==0)
            ans=root->val;
        fun(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        val=k;
        fun(root);
        return ans;
    }
};
*/

//Sol_2 28ms

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
        int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> sta;
        int maxV = k;
		
        while(sta.size() || root){
            while(root){
                sta.push(root);
                root = root->left;
            }
            TreeNode* top = sta.top();
            sta.pop();
            maxV--;
            if(maxV == 0)
                return top->val;
            root = top->right;
        }
        return 0;
    }
};
