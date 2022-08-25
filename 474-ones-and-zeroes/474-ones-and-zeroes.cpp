class Solution {
public:
    
    vector<vector<vector<int>>> dp;
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1)));
        
        for(int i=1;i<=strs.size();i++){
            
            int count_1 = count(strs[i-1].begin(),strs[i-1].end(),'1');
            
            int count_0 = strs[i-1].size() - count_1;
            
            for(int j=0;j<=m;j++){
                
                for(int k=0;k<=n;k++){
                    
                    if(j>=count_0 && k>=count_1)
                    {
                        int pick = 1 + dp[i-1][j-count_0][k-count_1];
                        
                        int nt_pick = dp[i-1][j][k];
                    
                        dp[i][j][k] = max(pick,nt_pick);
                    }
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        
        return dp[strs.size()][m][n];
        
    }
    
    int helper(vector<string>& strs, int m, int n,int ind){
        
        if(ind==strs.size())
            return 0;
        
        int count_1 = count(strs[ind].begin(),strs[ind].end(),'1');
        int count_0 = strs[ind].size() - count_1;
        
        if(dp[m][n][ind]!=-1)
            return dp[m][n][ind];
        
        int pick=INT_MIN;
        
        if(m>=count_0 && n>=count_1)
        {
            pick = 1 + helper(strs, m-count_0, n-count_1 , ind+1);
        }
        int nt_pick = helper(strs, m, n, ind+1);

        return dp[m][n][ind] = max(pick,nt_pick);
        
    }
};