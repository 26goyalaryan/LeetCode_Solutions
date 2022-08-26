class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(auto it:nums)
            sum+=it;
        
        if(sum%2==1)
            return false;
        
        int k=sum/2,n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
       
        return helper(n-1,k,nums,dp);
    }
    
    bool helper(int ind, int k, vector<int> &nums,vector<vector<int>> &dp){
        
        if(k==0)
            return true;
        
        if(ind==0)
            return (nums[0]==k) ? true : false;
        
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        
        bool pick=false;
        
        if(nums[ind]<=k)
            pick = helper(ind-1,k-nums[ind],nums,dp);
        
        
        bool nt_pick = helper(ind-1,k,nums,dp);
        
        return dp[ind][k] = (pick||nt_pick);
    }
};