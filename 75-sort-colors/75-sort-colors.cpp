class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int zero=0;
        while(l<=h){
            if(nums[l]==0){
                swap(nums[l],nums[zero]);
                zero++;
                l++;
            }else if(nums[l]==2){
                swap(nums[l],nums[h]);
                h--;
            }else
                l++;
        }
    }
};