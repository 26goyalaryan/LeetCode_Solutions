class Solution {
    // optimise the space complexity ---> no freq map ----> no ds to store permutation
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        addperm(0,nums,ans);
        return ans;
    }
private:
    void addperm(int ind,vector<int> &nums, vector<vector<int>> &ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            addperm(ind+1,nums,ans);
            swap(nums[ind],nums[i]); 
        }
    }
};