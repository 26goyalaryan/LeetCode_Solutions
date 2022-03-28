class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return true;
            // we have to deal with the case of duplicates where 
            //a[low]==a[mid]==a[high] , that will cause us problem
            //so will keep subtracting high and increment low accordingly.
            if(nums[low]==nums[mid] && nums[high]==nums[mid]){
                low++;
                high--;
            }
            
            // if left side is sorted
            else if(nums[low]<=nums[mid]){
                //try to find element inn left side
                if(target>=nums[low] && target<=nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else{
                if(target<=nums[high] && target>=nums[mid])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return false;
    }
};
