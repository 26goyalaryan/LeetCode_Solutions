class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        if(n<=1)
            return 1; 
        int left_call=1;
        int right_call=1;
        for(int i=2;i<=n;i++){
            int curi=left_call+right_call;
            left_call=right_call;
            right_call=curi;
        }
        return right_call;
    }
};
/*
private:
    int solve(int n,vector<int> &dp){
        // if standing at 0 -- 1 way to reach ie stand there only.
        // if standing at 0 and n = 1 ---> there is only 1 way to climb and ie take 1 step
        
        if(n<=1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        // total ways will be sum of all possible ways 
        // sum = when you take 1 step + when to take 2 step
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
*/