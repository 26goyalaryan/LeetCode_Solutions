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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string r1,r2;
        helper(root1,r1);
        helper(root2,r2);
        return r1==r2;
    }
private:
    void helper(TreeNode* root,string &r){
        if(root==NULL)
            return;
        if(!root->right && !root->left)
            r+=to_string(root->val)+'*';
        helper(root->left,r);
        helper(root->right,r);
    }
};