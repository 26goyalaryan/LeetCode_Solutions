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
    int count;
public:
    void helper(TreeNode* root,long long sum){
        
        if(root==NULL)
            return;
        
        if(sum==root->val)
            count++;
        
        sum-=root->val;
        
        helper(root->left,sum);
        helper(root->right,sum);
        
    }
    int pathSum(TreeNode* root, int sum) {
        
        if(root==NULL)
            return 0;
        
        helper(root,sum);
        
        pathSum(root->left,sum);
        
        pathSum(root->right,sum);
        
        return count;
    }
};