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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        map<int,int> inMap;
        for(int i=0;i<in.size();i++){
            inMap[in[i]]=i;
        }
        TreeNode* root=helper(pre,0,pre.size()-1,in,0,in.size()-1,inMap);
        return root;
    }
private:
    TreeNode* helper(vector<int>& pre,int pre_s,int pre_e,vector<int>& in,int in_s,int in_e,map<int,int>& inMap){
        if(pre_s>pre_e || in_s>in_e)
            return NULL;
        TreeNode* root= new TreeNode(pre[pre_s]);
        int idx_root = inMap[root->val];
        int pre_subtree=idx_root-in_s;
        root->left=helper(pre,pre_s+1,pre_s+pre_subtree,in,in_s,idx_root-1,inMap);
        root->right=helper(pre,pre_s+pre_subtree+1,pre_e,in,idx_root+1,in_e,inMap);
        return root;
    }
};