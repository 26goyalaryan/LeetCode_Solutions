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
    TreeNode* res;
public:
    TreeNode* getTargetCopy(TreeNode* org, TreeNode* clo, TreeNode* tar) {
        solve(org,clo,tar);
        return res;
    }
    void solve(TreeNode* org, TreeNode* clo, TreeNode* tar)
    {
        if(org==NULL)
            return;
        solve(org->left,clo->left,tar);
        if(org==tar){
            res=clo;
        }
        solve(org->right,clo->right,tar);
    }
};