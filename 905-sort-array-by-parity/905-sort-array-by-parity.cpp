class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if(nums[i]%2==0){
                // at start, even, at back odd
                // then continue
                if(nums[j]%2==1){
                    i++;j--;
                }
                // even at start, even at end
                // so may be nect no. at start is even so i++
                else
                    i++;
            }else if(nums[i]%2!=0 && nums[j]%2==1)
                // odd at back, so may be next elemt at j-1 is even.
                j--;
            else
                // if odd at start and even at end.
                // swap and move on.
                swap(nums[i],nums[j]);
        }
        return nums;
    }
};