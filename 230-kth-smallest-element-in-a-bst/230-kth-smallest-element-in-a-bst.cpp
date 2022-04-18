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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        helper(ans,root);
        return ans[k-1]; // return the k-1th element from starting as 1-indexed
    }
private:
    void helper(vector<int> &ans,TreeNode* root){
        // inorder traversal of BST return sorted values.
        if(root==NULL)
            return;
        if(root->left)
            helper(ans,root->left);
        ans.push_back(root->val);
        if(root->right)
            helper(ans,root->right);
    }
};