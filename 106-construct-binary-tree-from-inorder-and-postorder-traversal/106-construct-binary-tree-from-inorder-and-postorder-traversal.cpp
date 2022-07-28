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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return NULL;
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
private:
    TreeNode* helper(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe,unordered_map<int,int> &mp)
    {
        if(is>ie || ps>pe)
            return NULL;
        TreeNode* root= new TreeNode(postorder[pe]);
        int in_root=mp[postorder[pe]];
        int left_subtree=in_root-is;
        
        root->left=helper(inorder,is,in_root-1,postorder,ps,left_subtree+ps-1,mp);
        root->right=helper(inorder,in_root+1,ie,postorder,ps+left_subtree,pe-1,mp);
        
        return root;
    }
};