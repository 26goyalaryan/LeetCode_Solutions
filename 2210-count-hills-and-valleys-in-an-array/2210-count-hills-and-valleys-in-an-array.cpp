class Solution {
public:
    int countHillValley(vector<int>& nums) {
       int ans=0,n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            int left=i-1;
            int right=i+1;
            while(left>=0 && nums[left]==nums[i])
                left--;
            if(left<0)
                continue;
            while(right<n && nums[right]==nums[i])
                right++;
            if(right==n)
                continue;
            if(nums[left]<nums[i] && nums[right]<nums[i])
                ans++;
            else if(nums[left]>nums[i] && nums[right]>nums[i])
                ans++;
        }
        return ans;
    }
};