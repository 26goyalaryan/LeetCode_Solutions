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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        int leftsum=0;
        helper(root,leftsum);
        return leftsum;
    }
private: 
    void helper(TreeNode* root,int &leftsum){
        if(!root)
            return;
        if(root->left && !root->left->left && !root->left->right)
            leftsum+=root->left->val;
        helper(root->left,leftsum);
        helper(root->right,leftsum);
    }
};