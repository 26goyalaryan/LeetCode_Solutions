class Solution {
public:
    int search(vector<int>& nums, int target) {
        // we will check whether the  left half is sorted or right half is sorted
        
        // the half which is sorted, we will try to find element in that 
        // ie the element must lie b/w both corner indices of the half
        
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(nums[mid]==target)
                return mid;
            // if left half is sorted
            if(nums[low]<=nums[mid]){
                if(nums[mid]>=target && nums[low]<=target){
                    high=mid-1;
                }else
                    low=mid+1;
            }else{
                if(nums[mid]<=target && nums[high]>=target)
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};