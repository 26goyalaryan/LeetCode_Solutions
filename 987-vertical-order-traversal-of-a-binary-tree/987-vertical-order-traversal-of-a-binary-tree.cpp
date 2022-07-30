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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> nodes;
        
        queue<pair<TreeNode*,pair<int,int>>> todo;
        
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            
            TreeNode* node=p.first;
            int x=p.second.first;
            int y=p.second.second;
            
            nodes[x][y].insert(node->val);
            // pushing in vertical=x, level=y and value in multiset
            // multiset stores in ascending order allowing multiple copies
            
            if(node->left)
                todo.push({node->left,{x-1,y+1}});
            if(node->right)
                todo.push({node->right,{x+1,y+1}});
            
        }
        
        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int> level;
            for(auto q:p.second){
                level.insert(level.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(level);
        }
        return ans;
    }
};