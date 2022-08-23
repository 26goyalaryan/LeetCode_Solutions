class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1)
                    dp[i][j]=0;
                
                else if(i==0 && j==0)
                    dp[i][j]=1;
                
                else{
                    int up=0,left=0;

                    if(i>0){
                        up = dp[i-1][j];
                    }
                    if(j>0)
                        left = dp[i][j-1];
                    
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    int helper(int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(m>=0 && n>=0 &&  grid[m][n]==1)
            return 0;
        
        else if(m==0 && n==0)
            return 1;
        
        else if(m<0 || n<0)
            return 0;
        
        else if(dp[m][n]!=-1)
            return dp[m][n];
        
        else
            return dp[m][n] = helper(m-1,n,grid,dp) + helper(m,n-1,grid,dp);
    }
};