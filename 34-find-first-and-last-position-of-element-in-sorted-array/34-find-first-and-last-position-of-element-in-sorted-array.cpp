class Solution {
    /*
this can be donw using binary search as O(logn) time is required.
if we found element at mid, then we store its occurance index and for
first----> we make high=mid-1
last-----> we make low=mid+1;
*/
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        vector<int> ans;
        int first=-1,last=-1;
        // for first occurance
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        //for last occurance
        low=0;
        high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};