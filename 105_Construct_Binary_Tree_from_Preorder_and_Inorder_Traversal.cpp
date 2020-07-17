/*
Q;
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

//Sol:1 16ms
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int treeSize = preorder.size();
        if (treeSize == 0) {
            return NULL;
        }
        
        // build a hash table for fast lookup
        unordered_map<int, int> iIndexMap;
        for (int i = 0; i < treeSize; i++) {
            iIndexMap[inorder[i]] = i;
        }
        
        return buildTreeRecur(preorder, 0, inorder, 0, treeSize, iIndexMap);
    }
    TreeNode* buildTreeRecur(vector<int>& preorder, int pBegin, vector<int>& inorder, int iBegin, int treeSize, unordered_map<int, int>& iIndexMap) 
    {
        int rootVal= preorder[pBegin];
        TreeNode* root=new TreeNode(rootVal);
        if(treeSize == 1)
        {
            return root;
        }
        int iIndex=iIndexMap[rootVal];
        int leftSize = iIndex-iBegin;
        int rightSize = treeSize- leftSize -1;
        if(leftSize > 0)
        {
            root->left=buildTreeRecur(preorder, pBegin+1 , inorder , iBegin , leftSize , iIndexMap);
        }
         
        if (rightSize > 0) 
        {
            root->right = buildTreeRecur(preorder, pBegin + 1 + leftSize, inorder, iIndex + 1, rightSize, iIndexMap);
        }
        return root;
    }
};
*/


//Sol:2 16ms
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
   if(preorder.empty()){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* pre = root;
        stack<TreeNode*> st;
        st.push(root);
        int flag = 0;
        int pp = 1, pi = 0;
        while(pi < inorder.size()){
            if(!st.empty() && st.top()->val == inorder[pi]){
                pre = st.top();
                flag = 1;
                st.pop();
                ++pi;
            }else{
                TreeNode* tmp = new TreeNode(preorder[pp]);
                if(flag == 0){
                    pre->left = tmp;
                    pre = pre->left;
                }else{
                    pre->right = tmp;
                    pre = pre->right;
                    flag = 0;
                }
                st.push(tmp);
                ++pp;
            }
        }
        return  root;
    }
};
