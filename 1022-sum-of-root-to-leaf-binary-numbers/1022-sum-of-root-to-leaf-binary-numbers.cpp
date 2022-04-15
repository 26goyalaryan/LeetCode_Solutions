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

/*
    the ques will be solved using the left shift.
    10 ---> 100 
    then each element will be multiplied by 2 raised to the power no. of shifts 
    ie x<<1 then x*2^1;
    
    so new val=val*2^1 (left shift) + root->val* 2^0 (least significant bit)
*/
class Solution {
public:
    int sumRootToLeaf(TreeNode* root,int val=0) {
        if(root==NULL)
            return 0;
        //val=val*2+ root->val*1;
        val=(val<<1)|root->val; // left shift operator is used.
        return root->left==root->right ? val:
        sumRootToLeaf(root->left,val) //left subtree call
        + sumRootToLeaf(root->right,val);
    }
};