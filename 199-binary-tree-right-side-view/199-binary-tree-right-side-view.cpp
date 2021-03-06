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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root,ans,0);
        return ans;
    }
private:
    void helper(TreeNode* root,vector<int>& ans,int level){
        if(root==NULL)
            return;
        if(ans.size()==level)
            // to check whther it is the rightmost element in the level
            ans.push_back(root->val);
        helper(root->right,ans,level+1);
        // bcz first add right->right-> ....
        helper(root->left,ans,level+1);
    }
};