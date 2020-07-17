/*
Question:
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

//Sol:1 8ms recursive
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversal(root , res);
        return res;
    }
    void inorderTraversal(TreeNode* root, vector<int> &res)
    {
        if(root != NULL)
        {
            inorderTraversal(root->left , res);
            res.push_back(root->val);
            inorderTraversal(root->right, res);
        }
    }
};
*/

//Sol:2 0ms iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        stack<TreeNode*> s;
        if(root == NULL)
            return out;
        
        while(root !=  NULL || !s.empty())
        {
             while(root!=NULL)
            {
                s.push(root);
                root = root->left;
            }
            root =s.top();
            s.pop();
            out.push_back(root->val);
            root=root->right;
        }
        return out;
    }
};
