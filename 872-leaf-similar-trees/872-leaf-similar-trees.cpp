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
        string t1="",t2="";
        helper(root1,t1);
        helper(root2,t2);
        return t1==t2?true:false;
    }
    void helper(TreeNode* root,string &t){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            t+=to_string(root->val)+"*";
        helper(root->left,t);
        helper(root->right,t);
    }
};