/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) 
            return NULL;
        int curr=root->val;
        // if both on right, move right.
        if(p->val>curr && q->val>curr)
            return lowestCommonAncestor(root->right,p,q);
        // if both on left move left.
        if(p->val<curr && q->val<curr)
            return lowestCommonAncestor(root->left,p,q);
        return root; // split point ie one is on either side.
    }
};