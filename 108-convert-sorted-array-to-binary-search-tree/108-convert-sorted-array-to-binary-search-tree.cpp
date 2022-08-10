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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
private:
    TreeNode* helper(vector<int>& nums,int low,int high){
        if(low>high)
            return NULL;
        // apply binary search to array and since it is inorder... 
        // every mid is a root node 
        
        int mid=(low+high)/2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        
        // moving towards left
        root->left=helper(nums,low,mid-1);
         
        // moving towars right..
        root->right=helper(nums,mid+1,high);
        
        return root;
    }
};