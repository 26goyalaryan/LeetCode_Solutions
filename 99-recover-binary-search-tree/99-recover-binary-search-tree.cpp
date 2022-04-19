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
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;
    TreeNode* prev;
public:
    void recoverTree(TreeNode* root) {
        first=mid=last=NULL;
        prev=new TreeNode(INT_MIN);
        helper(root);
        if(first && last){
        // violation nodes are not adjacent
            swap(first->val,last->val);
        }
        else if(first && mid)
            swap(first->val,mid->val);
    }
private:
    void helper(TreeNode* root){
        if(root==NULL)
            return;
        helper(root->left);
        if(prev!=NULL && (root->val<prev->val))
        {
            // if its the first violation
            if(first==NULL){
                first=prev;
                mid=root;
            }
            else
                last=root;
        }
        // mark curr node as prev
        prev=root;
        helper(root->right);
    }
};