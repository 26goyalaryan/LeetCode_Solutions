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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y)
            return false;
        int p1=-1;
        int x1=findheight(root,p1,x,0);
        
        int p2=-1;
        int x2=findheight(root,p2,y,0);
        
        return (p1!=p2 && x1==x2);
    }
private: 
    int findheight(TreeNode* curr,int &parent,int val,int height){
        if(curr==NULL)
            return 0;
        if(curr->val==val) // if we found the value then we return its height else return 0
            return height;
        parent=curr->val;
        int left=findheight(curr->left,parent,val,height+1);
        if(left)
            return left; // ie we found here in left so no need to check the right side
        parent=curr->val; // backtracking updation of parent
        int right=findheight(curr->right,parent,val,height+1);
        return right;
    }
};