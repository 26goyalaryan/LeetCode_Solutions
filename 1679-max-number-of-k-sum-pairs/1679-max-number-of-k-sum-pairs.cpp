class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto it:nums){
           int temp=k-it;
            if(mp[temp]>0){
                ans++;
                mp[temp]--;
            }
            else
                mp[it]++;
        }
        return ans;
    }
};