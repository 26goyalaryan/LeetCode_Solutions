class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        
        // map stores element as a key and its appearing indexes in a vector as a value
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int deg=0;
        
        // we calculate degree by checking any elements most no. of appearences
        for(auto it:mp){
            deg=max(deg,int(it.second.size()));
        }
        int mini=nums.size();
        // maximum possible size of subarray is size of array
        
        for(auto it:mp){
            if(it.second.size()==deg){
                // if appearences == deg
                // then choose the minimum difference b/w 1st & last index of appearence
                mini=min(mini,it.second.back()-it.second[0]+1);
            }
        }
        return mini;
    }
};