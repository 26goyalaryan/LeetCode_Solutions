class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subset(0,nums,ds,ans);
        return ans;
    }
public:
    void subset(int ind,vector<int>&nums,vector<int> &ds,vector<vector<int>> &ans){
        if(ind==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        subset(ind+1,nums,ds,ans);
        ds.pop_back();
        subset(ind+1,nums,ds,ans);
    }
};