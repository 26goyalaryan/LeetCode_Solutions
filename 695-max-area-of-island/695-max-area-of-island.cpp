class Solution {
    int R,C;
    //bool visited[R][C];
public:
    int maxAreaOfIsland(vector<vector<int>>& g) {
        R=g.size();
        C=g[0].size();
        
        int maxi=0;
        for(int i=0;i<R;i++){
            
            for(int j=0;j<C;j++){
                
                if(g[i][j]==1){
                    
                    // modifying maxi for every 1 we encounter 
                    // and checking for all 4 direction adding that 1 to maxi
                    
                    maxi=max(maxi,helper(g,i,j));
                }
            }
        }
        return maxi;
    }
private:
    int helper(vector<vector<int>>& g,int i,int j){
        if(i>=0 && i<R && j>=0 && j<C && g[i][j]==1){
            
            g[i][j]=-1; // inorder to skip visited nodes
            
            // checking for all 4 directions 
            // left right up down
            
        return 1+ helper(g,i+1,j) + helper(g,i-1,j) + helper(g,i,j-1) + helper(g,i,j+1);
            
        }
        return 0;
    }
};