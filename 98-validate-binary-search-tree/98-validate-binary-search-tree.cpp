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

// for every node, we will check if the nodes val lies in valid range. 
// for left node (-infinity,root->val)
// for right node (root->val,+infinity)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check_BST(root,LONG_MIN,LONG_MAX);
    }
private:
    bool check_BST(TreeNode* root,long min,long max){
        if(root==NULL)
            return true;
        if(root->val>min && root->val<max)
        {
            // for left subtree, the min will remain same and max will be root's val
            bool left = check_BST(root->left,min,root->val);
            // for right subtree, the max will remain same and min will be root's val
            bool right = check_BST(root->right,root->val,max);
            return left && right;
        }
        else
            return false;
    }
};