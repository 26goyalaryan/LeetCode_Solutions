class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(auto it:nums)
            sum+=it;
        
        if(sum%2==1)
            return false;
        
        int k=sum/2,n=nums.size();
        
        if(n==1)
            return false;
        
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));

        for(int i=0;i<=n-1;i++)
            dp[i][0] = true; // for all caes where target is zero

        //dp[0][nums[0]] = true; // where the target == element at last index

        for(int ind = 1;ind<n;ind++){
            
            for(int j=1;j<=k;j++){
                
                bool ntpk = dp[ind-1][j];

                bool pick = false;

                if(j>=nums[ind])
                    
                    pick=dp[ind-1][j-nums[ind]];
                
                dp[ind][j]=(pick||ntpk);
            }
        }
        return dp[n-1][k];
    }
};