class Solution {
public:
    
    // we will initalise 3 pointers
    // low will point to 0th index along with zero pointer
    // zero will be kept that whenever we encounter an 1 , we swap it with zero , so all the zeros get placed before 1
    // high will be used for 2;
    void sortColors(vector<int>& nums) {
        int low=0,zero=low,high=nums.size()-1;
        while(low<=high){
            if(nums[low]==0){
                swap(nums[low],nums[zero]);
                low++;zero++;
                // now if next element is 1, we will swap it withzero whenever we encounter a zero.
            }
            else if(nums[low]==2){
                swap(nums[low],nums[high]);
                high--;
                // may be swapped element is 0, so we dont move low
            }
            else
                low++;
            // if encounter any 1 , keep moving and whenever encounter a zero, swap it;
        }
    }
};