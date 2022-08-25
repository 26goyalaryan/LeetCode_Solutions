class Solution {
public:
    
    vector<vector<vector<int>>> dp;
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        
        return helper(strs,m,n,0);
        
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