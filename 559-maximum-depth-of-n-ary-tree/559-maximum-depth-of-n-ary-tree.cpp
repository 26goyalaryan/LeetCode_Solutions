/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int depth=0;
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        helper(root,1);
        return depth;
    }
    
    void helper(Node* root,int ht){
        if(root==NULL)
            return;
        if(root->children.size()==0)
            depth=max(depth,ht);
        for(int i=0;i<root->children.size();i++){
            helper(root->children[i],ht+1);
        }
    }
};