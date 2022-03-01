class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        //initially mark freq of every element 0
        for(int i=0;i<nums.size();i++)
            freq[i]=0;
        select(nums,ds,ans,freq);
        return ans;
    }
private:
    void select(vector<int>&nums,vector<int>& ds,vector<vector<int>>& ans,int freq[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds); 
            // if the size of combination is same as of nums ie it is a permutation
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                // if freq==0 ie element is no picked.
                ds.push_back(nums[i]);
                freq[i]=1; // update its frequency.
                select(nums,ds,ans,freq);
                // when backtrack, set freq back to 0 and pop the element.
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
};