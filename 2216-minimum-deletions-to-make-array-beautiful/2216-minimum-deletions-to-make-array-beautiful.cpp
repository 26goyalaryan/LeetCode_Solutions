class Solution {
public:
    int minDeletion(vector<int>& nums) {
       int ans=0;
        // length should be even
        // element at odd index must not be same with previous even
        // and the new index after deletion will be
        // original_index - no_of_deletions
        // and deletion will be from left side
        for(int i=0;i<nums.size()-1;i++){
            if((i-ans)%2==0 && nums[i]==nums[i+1])
                ans++;
        }
        if((nums.size()-ans)%2)
                ans++;
            // if odd length, we will delete last element as oit wont affect the 
            // rest of the elements and array.
        return ans;
    }
};