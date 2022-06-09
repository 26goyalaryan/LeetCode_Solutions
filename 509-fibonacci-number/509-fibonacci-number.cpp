class Solution {
public:
    int fib(int n) {
        int prev2=0,prev1=1;
        if(n<=1)
            return n;
        for(int i=2;i<=n;i++){
            int curri=prev2+prev1;
            prev2=prev1;
            prev1=curri;
        }
        /*
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        */
        //vector<int> dp(n+1,-1);
        return prev1;
    }
/*
private:
    int solve(int n,vector<int> &dp){
        if(n<=1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        dp[n]=solve(n-1,dp)+solve(n-2,dp);
        return dp[n];
    }
*/
};