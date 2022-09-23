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
    bool isSubtree(TreeNode* s, TreeNode* r) {
        if(s==NULL)
            return false;
        else if(helper(s,r))
            return true;
        else 
            return (isSubtree(s->left,r) || isSubtree(s->right,r));
    }
    bool helper(TreeNode* s,TreeNode* r){
        if(s==NULL || r==NULL)
            return s==r;
        else
            return (s->val==r->val) && helper(s->left,r->left) && helper(s->right,r->right);
    }
};