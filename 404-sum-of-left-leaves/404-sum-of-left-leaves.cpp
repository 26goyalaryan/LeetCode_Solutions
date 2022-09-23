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
    int sum=0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        helper(root);
        return sum;
    }
    void helper(TreeNode* root){
        if(root==NULL)
            return;
        if(root->left && !root->left->left && !root->left->right)
            sum+=root->left->val;
        helper(root->left);
        helper(root->right);
    }
};