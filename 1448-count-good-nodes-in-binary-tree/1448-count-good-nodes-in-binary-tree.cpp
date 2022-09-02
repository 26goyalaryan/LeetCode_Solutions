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
    int ans;
public:
    int goodNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        ans=0;
        helper(root,-1e9);
        return ans;
    }
    void helper(TreeNode* root,int prev){
        if(root==NULL)
            return;
        else if(root->val>=prev){
            ans++;
        }
        prev=max(prev,root->val);
        helper(root->left,prev);
        helper(root->right,prev);
    }
};