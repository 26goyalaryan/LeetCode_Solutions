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
private:
    void inorder(TreeNode* root,vector<int> &in)
    {
        // store the inorder of tree.
        if(root==NULL)
            return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
TreeNode* bst(vector<int> &in,int s,int e)
    {
    // apply binary search and make the left and right subtree recursively.
        if(s>e)
            return NULL;
        int mid=(e-s)/2 + s;
        TreeNode* node=new TreeNode(in[mid]);
        node->left=bst(in,s,mid-1);
        node->right=bst(in,mid+1,e);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        return bst(in,0,in.size()-1);
    }
};