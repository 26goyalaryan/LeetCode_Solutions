class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            // if left side is sorted
            if(nums[low]<=nums[mid]){
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
        return -1;
    }
};