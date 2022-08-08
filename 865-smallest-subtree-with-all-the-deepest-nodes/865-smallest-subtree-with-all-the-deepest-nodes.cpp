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
    TreeNode* res=NULL;
    int max_depth=-1;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL)
            return NULL;
        helper(root,0);
        return res;
    }
    
    int helper(TreeNode* root,int depth){
        if(root==NULL)
            return depth;
        int lh= helper(root->left,depth+1);
        int rh= helper(root->right,depth+1);
        
        if(lh==rh)
        {
            max_depth=max(max_depth,lh);
            
            if(max_depth==lh)
                res=root;
        }
        return max(lh,rh);
    }
};