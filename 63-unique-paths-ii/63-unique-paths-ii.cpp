class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,grid,dp);
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