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
        TreeNode* prev=NULL;
        return checkBST(root,prev);
    }
    
    //we will be doing inorder traversal and as soon as we find BST condition voilated, we return false.
    // else we will be keeping the prev node updating .
    
private:
    bool checkBST(TreeNode* root,TreeNode* &prev){ 
        //prev by reference bcz we need to update it everytime we call for left or right subtree
        if(!root) 
            return true; // base case 
        if(!checkBST(root->left,prev))
            return false; // function call for left subtree - inorder traversal.
        if(prev && prev->val>=root->val)
            return false;
        prev=root; // update prev to root everytime we found BST condition satisfied.
        return checkBST(root->right,prev);    // right subtree recursion call
    }
};