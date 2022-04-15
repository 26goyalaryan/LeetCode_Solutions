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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(ans,root,to_string(root->val));
        return ans;
    }
    void helper(vector<string> &ans,TreeNode *root,string l){
        if(!root->right && !root->left)
            ans.push_back(l);
        if(root->left)
            helper(ans,root->left,l+"->"+to_string(root->left->val));
        if(root->right)
            helper(ans,root->right,l+"->"+to_string(root->right->val));
    }
};