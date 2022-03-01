class Solution {
private:
    // here we will not choose the element but we choose the combination and if its sum = target we 
    // will push.
    void fcombination(int ind,int target,vector<int> &arr,vector<int> &ds,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(ds); // base case -> if all the elements forms target sum.
            return;
        }
        for(int i=ind;i<arr.size();i++){
            
            // if the element is not picked up in the combination for the first time and 
            // index is value is similar to previous one
            
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(target<arr[i]) break; // if element to be put in combination is greater than target.
            ds.push_back(arr[i]);
            fcombination(i+1,target-arr[i],arr,ds,ans);
            ds.pop_back(); // pop back when the left recursion call over
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end()); // sort the array so that we can cover duplicates
        fcombination(0,target,candidates,ds,ans);
        return ans;
    }
};