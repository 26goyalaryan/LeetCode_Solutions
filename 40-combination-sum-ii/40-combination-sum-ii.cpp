class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        helper(nums,ans,target,ds,0);
        return ans;
    }
    
    void helper(vector<int> &nums,vector<vector<int>> &ans,int target,vector<int> &ds,int ind){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])
                continue;
            if(nums[i]>target)
                break;
            ds.push_back(nums[i]);
            helper(nums,ans,target-nums[i],ds,i+1);
            ds.pop_back();
        }
    }
};