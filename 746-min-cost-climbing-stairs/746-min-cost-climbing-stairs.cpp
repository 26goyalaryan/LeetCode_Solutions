class Solution {
    
public:
    int minCostClimbingStairs(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return min(helper(nums,dp,n-1),helper(nums,dp,n-2));
    }
private:
    int helper(vector<int>& nums,vector<int>& dp,int n){
        if(n<0)
            return 0;
        if(n==0 || n==1)
            return nums[n];
        /*
        return nums[n] + min(helper(nums,n-1),helper(nums,n-2));
        */
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=nums[n]+min(helper(nums,dp,n-1),helper(nums,dp,n-2));
    }
};