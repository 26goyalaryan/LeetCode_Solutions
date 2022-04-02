class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(auto it:arr1){
            mp[it]++;
        }
        vector<int> ans;
        for(auto it:arr2){
            if(mp[it]>0){
                while(mp[it]){
                    ans.push_back(it);
                    mp[it]--;
                }
            }
        }
        int size=ans.size();
        for(auto it:mp){
            if(it.second>0){
                while(it.second){
                    ans.push_back(it.first);
                    it.second--;
                }
            }
        }
        sort(ans.begin()+size,ans.end());
        return ans;
    }
};