class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0,target=(n*(n+1))/2;
        for(auto it:nums)
            sum+=it;
        return target-sum;
    }
};