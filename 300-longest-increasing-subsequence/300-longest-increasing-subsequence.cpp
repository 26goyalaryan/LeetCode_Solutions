class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=1;
        vector<int> prefix(nums.size(),1);
        
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                
                if(nums[j]<nums[i])
                {
                    prefix[i]=max(prefix[i],prefix[j]+1);
                    ans=max(ans,prefix[i]);
                }
            }
        }
        return ans;
    }
};