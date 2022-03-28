class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        // O(n) 2 pointer approach.  
        while(low<=high){
            if(nums[low]==target || nums[high]==target)
                return true;
            else if(target>nums[low]){
                while(low<high && nums[low]==nums[low+1])
                    low++;
                low++;
            }
            // on right half
            else if(target<nums[high]){
                while(low<high && nums[high]==nums[high-1])
                    high--;
                high--;
            }
            // not found
             else
                 break;
        }
        return false;
    }
};
