class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(nums,0,ds,target,ans);
        return ans;
    }
private:
    void solve(vector<int> &nums,int ind,vector<int> &ds,int target,vector<vector<int>> &ans){
        if(ind==nums.size()){
            if(target==0)
                ans.push_back(ds);
            return;
        }
        if(nums[ind]<=target){
            ds.push_back(nums[ind]);
            solve(nums,ind,ds,target-nums[ind],ans);
            ds.pop_back();
        }
        solve(nums,ind+1,ds,target,ans);       
    }
};