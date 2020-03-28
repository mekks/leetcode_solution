/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 */
 class Solution {
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end){
        if(end<=start) return NULL; 
        int midIdx=(end+start)/2;
        //int midIdx =start+(end-start)/2;
        TreeNode* root=new TreeNode(nums[midIdx]);
        root->left=sortedArrayToBST(nums, start, midIdx);
        root->right=sortedArrayToBST(nums, midIdx+1,end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0,nums.size());
    }
};
