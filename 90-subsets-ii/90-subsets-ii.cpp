class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0,nums,ds,ans);
        return ans;
    }
private:
    void solve(int ind,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1])
                continue;
            ds.push_back(nums[i]);
            solve(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
};