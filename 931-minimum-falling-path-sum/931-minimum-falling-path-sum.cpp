class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        int m=matrix.size();
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        
        for(int i=1;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                int up=matrix[i][j] + dp[i-1][j],leftd=1e9,rightd=1e9;
                
                if(j>0)
                    leftd= matrix[i][j] + dp[i-1][j-1];
                
                if(j<n-1)
                    rightd = matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j]=min(up,min(leftd,rightd));
            }
        }
        
        int mini=1e9;
        
        for(int i=0;i<n;i++)
            mini = min(mini,dp[m-1][i]);
        
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