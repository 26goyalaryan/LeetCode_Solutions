class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> ds;
        helper(target,n,nums,ans,ds,0);
        return ans;
    }
    void helper(int target,int n,vector<int> &nums, vector<vector<int>> &ans,vector<int> &ds,int ind){
        if(ind==n){
            if(target==0)
                ans.push_back(ds);
            return;
        }
        if(nums[ind]<=target)
        {
            ds.push_back(nums[ind]);
            helper(target-nums[ind],n,nums,ans,ds,ind);
            ds.pop_back();
        }
        helper(target,n,nums,ans,ds,ind+1);
    }
};