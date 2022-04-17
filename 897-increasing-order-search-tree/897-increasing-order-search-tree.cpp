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
    TreeNode* curr=new TreeNode(0); //globally declared curr pointer.
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans=curr;
        helper(root);
        return ans->right;
    }
private:
    void helper(TreeNode* root){
        if(root==NULL)
            return;
        helper(root->left); // reach out to left most node
        root->left=NULL; // making every node's left = NULL
        curr->right=root; // updating curr's right to root.
        curr=root; // updating curr to next right node
        helper(root->right); // calling for right node;
    }
};