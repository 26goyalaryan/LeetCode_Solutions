class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp);
    }
    int helper(int m,int n,vector<vector<int>> &dp){
        if(m<0 || n<0)
            return dp[m][n]=0;
        else if(m==0 || n==0)
            return dp[m][n]=1;
        else if(dp[m][n]!=-1)
            return dp[m][n];
        else
            return dp[m][n] = helper(m-1,n,dp) + helper(m,n-1,dp);
    }
};