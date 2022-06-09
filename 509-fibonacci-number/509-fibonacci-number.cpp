class Solution {
public:
    int fib(int n) {
        /*
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        */
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
private:
    int solve(int n,vector<int> &dp){
        if(n<=1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        dp[n]=solve(n-1,dp)+solve(n-2,dp);
        return dp[n];
    }
};