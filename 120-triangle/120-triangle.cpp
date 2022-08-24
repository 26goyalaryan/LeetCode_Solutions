class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(triangle[n-1].size(),0));
        
        // fill the base case in table 
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        
        // go opposite to recursion 
        // recursion was f(0,0) ---> f(n-1,n-1)
        // tabulation goes from last to (0,0)
        // the main recurrance remains same 
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
    
    int helper(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> &dp){
        
        if(i==triangle.size()-1)
            return triangle[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int same_row = triangle[i][j] + helper(i+1,j,triangle,dp);
        
        int diag = triangle[i][j] + helper(i+1,j+1,triangle,dp);
        
        return dp[i][j]=min(same_row,diag);
    }
};