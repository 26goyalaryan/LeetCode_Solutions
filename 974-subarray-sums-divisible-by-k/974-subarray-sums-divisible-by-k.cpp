class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        // if at any point, the rem of commulative sum % k appears than ones.
        // then sum of elements in b/w must be equal to k
        
        
        // so num of subarrays will be freq of that remainders
        int ans=0;
        int n=nums.size();
        int curr_sum=0;
        if(n==0)
            return 0;
        unordered_map<int,int> mp;
        mp[0]=1; // initial commulative sum =0;
        for(auto it:nums){
            curr_sum+=it;
            int rem=curr_sum%k;
            if(rem<0)
                rem+=k; // if it = -1, then -1%5 = -1, but we need rem as 4 .
            // ie we are handeling negative remainder 
            // 11%3 = 2, but negative rem = -1 (12-1) 
            // so to get + rem from neg is rem + no. ie (-1 + 3 = 2 )
            
            // no. of non empty subarrays of length n = n;
            if(mp[rem]>0)
                ans+=mp[rem];
            
            mp[rem]++;
        }
        return ans;
    }
};