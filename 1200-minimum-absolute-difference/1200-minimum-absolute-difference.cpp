class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int min_diff=INT_MAX;
        for(int i=1;i<arr.size();i++){
            min_diff=min(min_diff,arr[i]-arr[i-1]);
        }
        vector<vector<int>> ans;
        for(int i=1;i<arr.size();i++){
            vector<int> ds(2,0);
            if(arr[i]-arr[i-1]==min_diff){
                ds[0]=arr[i-1];
                ds[1]=arr[i];
                ans.push_back(ds);
            }
        }
        return ans;
    }
};