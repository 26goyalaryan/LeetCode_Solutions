class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int br_pt,n=nums.size(),swp_pt;
        
        for(br_pt=n-2;br_pt>=0;br_pt--){
            if(nums[br_pt]<nums[br_pt+1])
                break;
        }
        if(br_pt<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        else{
            for(swp_pt=n-1;swp_pt>br_pt;swp_pt--){
                if(nums[swp_pt]>nums[br_pt])
                    break;
            }
        }
        swap(nums[br_pt],nums[swp_pt]);
        reverse(nums.begin()+br_pt+1,nums.end());
    }
};