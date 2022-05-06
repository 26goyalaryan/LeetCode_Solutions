class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n=nums.size();
        int freq[n];
        for(int i=0;i<n;i++)
            freq[i]=0;
        solve(ans,ds,nums,freq);
        return ans;
    }
private:
    void solve(vector<vector<int>> &ans,vector<int> &ds,vector<int> &nums,int freq[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                solve(ans,ds,nums,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
};