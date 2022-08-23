class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        
        int n=grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return helper(m-1,n-1,grid,dp);
    }
    
    int helper(int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        
        if(m==0 && n==0)
            return grid[m][n];
        
        if(m<0 || n<0)
            return 0;
        
        if(m==0)
            return dp[m][n] = grid[m][n] + helper(m,n-1,grid,dp);
        
        if(n==0)
            return dp[m][n] = grid[m][n] + helper(m-1,n,grid,dp);
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        return dp[m][n] = grid[m][n] + min(helper(m-1,n,grid,dp),helper(m,n-1,grid,dp));
    }
};