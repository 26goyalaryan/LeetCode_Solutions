class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<char>> temp;
        vector<char> nums={'a','e','i','o','u'};
        vector<char> ds;
        solve(0,nums,ds,temp,n);
        return temp.size();
    }
private:
    void solve(int start,vector<char> &nums,vector<char> &ds,vector<vector<char>> &temp,int n){
        if(ds.size()==n){
            temp.push_back(ds);
            return;
        }
        for(int i=start;i<nums.size();i++){
            ds.push_back(nums[i]);
            solve(i,nums,ds,temp,n);
            ds.pop_back();
        }
    }
};