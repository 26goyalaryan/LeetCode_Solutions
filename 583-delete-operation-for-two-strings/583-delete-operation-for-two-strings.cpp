class Solution {
public:
    int minDistance(string w1, string w2) {
        int s1=w1.size(),s2=w2.size();
        vector<vector<int>> dp(s1+1,vector<int> (s2+1));
        for(int i=s1;i>=0;i--){
            for(int j=s2;j>=0;j--){
                if(i<s1 || j<s2){
                    if(i<s1 && j<s2 && w1[i]==w2[j])
                        // traversing from back and storing final ans in [0][0]
                        // if char equal then move fwd
                        dp[i][j]=dp[i+1][j+1];
                    // else considering every case 
                    // 1st deleting from w1
                    // then from w2.
                    else{
                        dp[i][j]=1+min(i<s1 ? dp[i+1][j]:INT_MAX, j<s2 ? dp[i][j+1]:INT_MAX);
                    }
                }
            }
        }
        return dp[0][0];
    } 
/*
    int minDistance(string w1, string w2) {
        int s1=w1.size(),s2=w2.size();
        return solve(w1,w2,0,0,s1,s2);
    }
private:
    int solve(string w1, string w2,int i,int j,int s1,int s2){
        // explored both words and at the end now
        if(i==s1 && j==s2)
            return 0;
        // explored one of the strings fully, return no. of characters left
        if(i==s1)
            return s2-j;
        if(j==s2)
            return s1-i;
        // if char at both i, j equal --> continue
        if(w1[i]==w2[j])
            return solve(w1,w2,i+1,j+1,s1,s2);
        // else explore all the possible outcomes one by one
        // first deleting the ith char and then jth
        return 1 + min(solve(w1,w2,i+1,j,s1,s2),solve(w1,w2,i,j+1,s1,s2));
        
        // 1 --> cost for deleting the current char .
        
    }
*/ 
};