class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>> memo(n1+1,vector<int>(n2+1,-1));
        return helper(s1,s2,n1-1,n2-1,memo);
    }
     int helper(string &text1, string &text2,int m,int n,vector<vector<int>> &memo) {
        if(m<0 || n<0){
            return 0;
        }
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        if(text1[m]==text2[n]){
            return memo[m][n]= 1+helper(text1,text2,m-1,n-1,memo);
        }else{
            return memo[m][n]= max(helper(text1,text2,m-1,n,memo),helper(text1,text2,m,n-1,memo));
        }
    }
};