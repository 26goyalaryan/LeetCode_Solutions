class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            //cout<<mp[target-nums[i]];
            if(mp.find(target-nums[i])!=mp.end()){
            //if(mp[target-nums[i]]>0){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            else
                mp[nums[i]]=i;
        }
        return ans;
    }
};