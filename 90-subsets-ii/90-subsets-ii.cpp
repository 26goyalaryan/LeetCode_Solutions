class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        helper(nums,ds,ans,0);
        return ans;
    }
    
    void helper(vector<int>& nums,vector<int>& ds,vector<vector<int>> &ans,int ind){
            ans.push_back(ds);
            //return;
        for(int i=ind;i<nums.size();i++){
            if(ind != i && nums[i]==nums[i-1])
                continue;
            ds.push_back(nums[i]);
            helper(nums,ds,ans,i+1);
            ds.pop_back();
            //helper(nums,ds,ans,i+1);
        }
    }
};