/*
QUESTION:
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.
*/

//RECURSIVE:
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       return !root || isMirror(root->left, root->right);
    }
    public:
    bool isMirror(TreeNode* t1,TreeNode* t2)
    {
        if(t1 == NULL && t2 == NULL)return true;
        if(t1 == NULL || t2 == NULL)return false;
        return (t1->val == t2->val) && isMirror(t1->right ,t2->left) && isMirror(t1->left ,t2->right);
    }
};
//ITERATIVE:
/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return iterative(root);
    }
    
    // iterative
    bool iterative(TreeNode* root) {
        if (!root) return true;
        stack<vector<TreeNode *>> s({vector<TreeNode*>({root->left, root->right})});
        while(!s.empty()) {
            TreeNode *t1 = s.top()[0], *t2 = s.top()[1]; s.pop();
            
            if (!t1 && !t2) continue;
            if (!t1 || !t2) return false;
            if (t1->val != t2->val) return false;
            s.push({t1->left, t2->right});
            s.push({t1->right, t2->left});
        }
        return true;
    }
};
*/
