/*
Qu:
ven a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

//Sol:1 8ms
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> out; 
        queue<TreeNode*> nodes;
        nodes.push(root);//initially root node enqueue in queue
        
        TreeNode* front;//temp node var
        vector<int> level;
        
        while(!nodes.empty())
        {
            int size=nodes.size();
            level.reserve(size);//reserve size for level array
            
            for(int i=0;i<size; i++)
            {
                front=nodes.front();
                nodes.pop();
                level.push_back(front->val);
                if(front->left)nodes.push(front->left);
                if(front->right)nodes.push(front->right);
            }
            out.push_back(level);
            level.clear();
        }
        return out;
    }
};
