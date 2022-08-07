class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        string ans;
        int maxi=0;
        
        // diff variable is the difference of i & j
        // and we will increment diff each time.
        
        // and in inner loop we will i+1,j+1 till j<n
        
        for(int diff=0;diff<n;diff++){
            
            for(int i=0,j=diff+i;j<n;i++,j++){
                
                if(i==j)
                    dp[i][j]=1;
                else if(diff==1)
                    dp[i][j]=(s[i]==s[j]) ? 2 : 0;
                else{
                    dp[i][j] = (s[i]==s[j] && (dp[i+1][j-1]!=0)) ? 2 + dp[i+1][j-1] : 0;
                }
                
                if(dp[i][j]){
                    if(maxi<j-i+1){
                        maxi=j-i+1;
                        ans=s.substr(i,j-i+1);
                        // substr takes 2 arg, i is start index, other is length
                    }
                }
            }
        }
        return ans;
    }
};