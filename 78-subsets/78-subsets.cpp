class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        //int n=nums.size();
        vector<int> ds;
        solve(nums,0,ds,ans);
        return ans;
    }
private:
    void solve(vector<int>& nums,int ind,vector<int> &ds,vector<vector<int>> &ans){
        if(ind==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        solve(nums,ind+1,ds,ans);
        ds.pop_back();
        solve(nums,ind+1,ds,ans);
    }
};