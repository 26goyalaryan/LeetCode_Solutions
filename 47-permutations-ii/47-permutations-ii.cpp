class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>>s;
        addperm(0,nums,s,ans);
        return ans;
    }
private:
    void addperm(int ind,vector<int> &nums,set<vector<int>> &s,vector<vector<int>> &ans){
        if(ind==nums.size() && s.find(nums)==s.end()){
            ans.push_back(nums);
            s.insert(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            addperm(ind+1,nums,s,ans);
            swap(nums[ind],nums[i]); 
        }
    }
};