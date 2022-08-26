class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        int m=matrix.size();
        int mini=INT_MAX;
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int j=0;j<n;j++){
            mini=min(mini,helper(m-1,j,matrix,m,n,dp)); // exploring all end points.
        }
        
        return mini;
    }
    
    int helper(int i,int j,vector<vector<int>>& matrix,int m,int n,vector<vector<int>>& dp){
        // out of bound cases
        
        if(j<0 || j>=n)
            return 1e9; // not returning INT_MAX to avoid overflow
        
        // destination case
        if(i==0)
            return dp[i][j] = matrix[i][j]; // return element at that very column in 1st row
        
        // 3 possible ways to travel back
        
        if(dp[i][j]!=-1)
            
            return dp[i][j];
        
        int strght = matrix[i][j] + helper(i-1,j,matrix,m,n,dp);
        
        int leftd = matrix[i][j] + helper(i-1,j-1,matrix,m,n,dp);
        
        int rghtd = matrix[i][j] + helper(i-1,j+1,matrix,m,n,dp);
        
        return dp[i][j] = min(strght,min(leftd,rghtd));
        
    }
};