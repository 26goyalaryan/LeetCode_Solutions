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
    unordered_map<int,int> mp;
public:
    TreeNode* helper(vector<int>& pre, vector<int>& post,int prestart,int preend,int poststart,int postend){
        if(preend<prestart)
            return NULL;
        
        TreeNode* root= new TreeNode(pre[prestart]);
        if(prestart==preend)
            return root;
        int idx=mp[pre[prestart+1]];
        int offset = idx-poststart;
        
        root->left = helper(pre,post,prestart+1,prestart+offset+1,poststart,idx);
        
        root->right = helper(pre,post,prestart+1+offset+1,preend,idx+1,postend);
        
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        for(int i=0;i<n;i++){
            mp[post[i]] = i;
        }
        return helper(pre,post,0,n-1,0,n-1);
    }
};