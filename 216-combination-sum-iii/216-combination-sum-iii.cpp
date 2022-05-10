class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(1,k,n,ds,ans);
        return ans;
    }
private:
    void solve(int start,int k,int n,vector<int> &ds,vector<vector<int>> &ans){
        //if(k<0 || n<0)
    //  return;
        // base case - condition satisfied
        if(k==0 && n==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=start;i<=9;i++){
            ds.push_back(i);
            solve(i+1,k-1,n-i,ds,ans);
            ds.pop_back();
        }
    }
};