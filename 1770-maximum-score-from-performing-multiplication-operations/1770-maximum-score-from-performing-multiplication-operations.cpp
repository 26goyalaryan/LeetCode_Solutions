class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        
        //int n=nums.size();
        vector<vector<int>> dp(1000,vector<int>(1000,-1e9));
        return helper(nums,multi,dp,0,0,nums.size()-1);
        
    }
    
    int helper(vector<int>& nums, vector<int>& multi,vector<vector<int>> &dp,int i,int l,int r){
        
        if(i==multi.size())
            return 0;
        
        if(dp[l][i]!=-1e9)
            return dp[l][i];
        
        int left = multi[i]*nums[l] + helper(nums,multi,dp,i+1,l+1,r);
        
        int right = multi[i]*nums[r] + helper(nums,multi,dp,i+1,l,r-1);
        
        dp[l][i] = max(left,right);
        
        return dp[l][i];
    }
};