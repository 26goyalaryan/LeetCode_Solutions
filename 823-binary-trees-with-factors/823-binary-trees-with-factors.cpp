class Solution {
    int mod=pow(10,9)+7;
public:
    int numFactoredBinaryTrees(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        unordered_map<int,long> mp;
        
        mp[nums[0]]=1;
        
        for(int i=1;i<nums.size();i++){
            long count=1;
            
            for(auto it:mp){
                
                int ele=it.first;
                
                if(nums[i]%ele==0 && mp.find(nums[i]/ele) != mp.end())
                    count+=mp[ele]*mp[nums[i]/ele];
                
            }
            mp[nums[i]]=count;
        }
        
        int ans=0;
        for(auto it:mp){
            ans=(ans+it.second)%mod;
        }
        return ans;
    }
};