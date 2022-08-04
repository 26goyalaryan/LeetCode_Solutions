class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int maxi=INT_MIN;
        for(auto it:nums){
            prod*=it;
            maxi=max(maxi,prod);
            if(prod==0)
                prod=1;
        }
        // now we have a case that what if there is a negative no. in start and no further
        // negatives. this will give us negative result
        
        // eg: 3 -1 4
        // ans: 3
        // actual ans: 4
        
        // so we will traverse form back also
        
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            maxi=max(prod,maxi);
            if(prod==0)
                prod=1;
        }
        return maxi;
    }
};