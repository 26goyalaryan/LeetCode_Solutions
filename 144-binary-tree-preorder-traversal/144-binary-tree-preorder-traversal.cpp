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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        pre(ans,root);
        return ans;
    }
public:
    void pre(vector<int> &ans,TreeNode* root){
        if(root==NULL)
            return;
        ans.push_back(root->val);
        pre(ans,root->left);
        pre(ans,root->right);
    }
};