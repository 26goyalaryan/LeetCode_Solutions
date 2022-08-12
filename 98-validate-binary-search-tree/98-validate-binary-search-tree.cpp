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
        if(root==NULL)
            return true;
        return helper(root,LONG_MIN,LONG_MAX);
    }
    
    bool helper(TreeNode* root,long min,long max)
    {
        if(root==NULL)
            return true;
        if(root->val > min && root->val < max){
            
            // when we move to left... the root value become max..
            bool left=helper(root->left,min,root->val);
            
            // when we move to right.. the root value become min
            bool right=helper(root->right,root->val,max);
            
            return left && right;
        }
        else
            return false;
    }
};