class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(triangle[n-1].size(),-1));
        return helper(0,0,triangle,dp);
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