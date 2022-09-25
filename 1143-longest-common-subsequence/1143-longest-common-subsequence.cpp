class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>> memo(1001,vector<int>(1001,-1));
        return longestCommonSubsequence(s1,s2,n1,n2,memo);
    }
    /*
    int helper(int i1,int i2,string s1,string s2,vector<vector<int>> &dp){
        if(i1<0 || i2<0)
            return 0;
        
        if(dp[i1][i2] != -1)
            return dp[i1][i2];
        
        if(s1[i1]==s2[i2])
            return dp[i1][i2] = 1 + helper(i1-1,i2-1,s1,s2,dp);
        
         return dp[i1][i2] = max(helper(i1-1,i2,s1,s2,dp),helper(i1,i2-1,s1,s2,dp));
         */
    int longestCommonSubsequence(string &text1, string &text2,int m,int n,vector<vector<int>> &memo) {
        if(m==0 || n==0){
            return 0;
        }
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            return memo[m][n]= 1+longestCommonSubsequence(text1,text2,m-1,n-1,memo);
        }else{
            return memo[m][n]= max(longestCommonSubsequence(text1,text2,m-1,n,memo),longestCommonSubsequence(text1,text2,m,n-1,memo));
        }
    }
};