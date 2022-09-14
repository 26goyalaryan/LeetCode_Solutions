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
    void helper(TreeNode* root,vector<int> &freq){
        
        // a number can be palindromic if only 1 no. has odd occurances.
        // it means there exist a permutation which is palindromic
        
        // eg: 12521 .. 1->2, 2->2, 5->1 ..
        // but 124521 .. 1->2, 2->2, 4->1, 5->1 ... not a palindrome
        
        if(root==NULL)
            return;
        
        freq[root->val]++; // increment the freq of curr root
        
        helper(root->left,freq);
        helper(root->right,freq);
        
        if(root->left==NULL && root->right==NULL){
            
            int odd_count=0; // count for odd freqs
            
            for(int it=1;it<=9;it++)
            {
                if(freq[it]%2)
                    odd_count++;
            }
            
            if(odd_count<=1) //if odd freq are 0 or 1. then increase the total count
                count++;
        }
        
        freq[root->val]--; // backtracking step for reducing the freq of current root node
        
    }
    int pseudoPalindromicPaths (TreeNode* root){
        
        if(root==NULL)
            return 0;
        
        vector<int> freq(10,0); // since root node values are only from [1,9]
                        
        helper(root,freq);
        
        return count;
    }
};