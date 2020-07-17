/*
Q:
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

//Sol:1 12ms
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> out; 
        queue<TreeNode*> nodes;
        nodes.push(root);//initially root node enqueue in queue
        
        TreeNode* front;//temp node var
        vector<int> level;
        int l=0;  //indicate the level from 0 to n
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
            if(l%2==1)
            {
                reverse(level.begin(),level.end());
            }
            l++;
            out.push_back(level);
            level.clear();
            
        }
        return out;
        
    }
};
*/

//Sol:2 8ms
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> out; 
        queue<TreeNode*> nodes;
        nodes.push(root);//initially root node enqueue in queue
        
        TreeNode* front;//temp node var
        vector<int> level;
        bool flag=true; 
        while(!nodes.empty())
        {
            int size=nodes.size();
            level.reserve(size);//reserve size for level array
            
            for(int i=0;i<size; i++)
            {
                front=nodes.front();
                nodes.pop();
                if(flag)
                {
                    level.push_back(front->val);
                }
                else
                {
                    level.insert(level.begin(),front->val);
                }
                if(front->left)nodes.push(front->left);
                if(front->right)nodes.push(front->right);
            }
            flag=!flag;
            out.push_back(level);
            level.clear();
            
        }
        return out;
        
    }
};
