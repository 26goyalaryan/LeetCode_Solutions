class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        /*
        s1 - s2 = target
        totalsum = s1 + s2;
        => totalsum - s1 - s1 = d
        => (totalsum - d ) = 2s1
        => s1 = (totalsum-d)/2
        now we have to find count of subsets with s1 sum
        */
          
        
        int n=nums.size();

        int sum = 0;
        for(auto it:nums)
            sum+=it;
        
        if(sum-target<0 || (sum-target)%2!=0)
            return 0;
        
        int s1 = (sum - target)/2;
        
        vector<vector<int>> dp(n,vector<int>(s1+1,-1));
        
        return helper(n-1,nums,dp,s1);
    }
    
    int helper(int ind,vector<int> &nums,vector<vector<int>> &dp,int target){
        
        if(ind==0){
            if(target==0 && nums[ind]==0)
                return 2;
            if(target==0 || nums[ind]==target)
                return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        int pick=0,nt_pick=0;
        
        nt_pick = helper(ind-1,nums,dp,target);
        
        if(nums[ind]<=target)
            pick = helper(ind-1,nums,dp,target-nums[ind]);
        
        return dp[ind][target] = pick+nt_pick;
    }
};