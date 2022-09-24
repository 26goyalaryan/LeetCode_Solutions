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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int first,last;
            int size=q.size();
            int mini=q.front().second;
            for(int i=0;i<size;i++){
                int curr=q.front().second-mini;
                if(i==0)
                    first=curr;
                if(i==size-1)
                    last=curr;
                TreeNode* node = q.front().first;
                q.pop();
                if(node->left){
                    q.push({node->left,(long)2*curr});
                }
                if(node->right){
                    q.push({node->right,(long)2*curr+1});
                }
                ans=max(ans,last-first+1);
            }
        }
        return ans;
    }
};