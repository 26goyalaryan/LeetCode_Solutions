class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,zero=0,high=nums.size()-1;
        while(low<=high){
            if(nums[low]==0){
                swap(nums[low],nums[zero]);
                low++,zero++;
            }
            else if(nums[low]==2){
                swap(nums[low],nums[high]);
                high--;
            }
            else
                low++;
        }
    }
};