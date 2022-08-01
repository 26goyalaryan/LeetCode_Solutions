class Solution {
public:
    int uniquePaths(int m, int n) {
        // we will count ways to reach (0,0) by either moving left or up
        // for any cell cells[i,j], total ways to reach this will be 
        // cells[i,j]= cells[i-1][j] + cells[i][j-1];
        
        vector<vector<int>> dp(m,vector<int> (n,0));
        return helper(m-1,n-1,dp);
    }
    int helper(int m,int n,vector<vector<int>> &dp){
        if(m<0 || n<0)
            return dp[m][n]=0;
        else if(m==0 || n==0)
            return dp[m][n]=1;
        else if(dp[m][n]!=0)
                return dp[m][n];
        else
            return dp[m][n]=helper(m-1,n,dp)+helper(m,n-1,dp);
    }
};