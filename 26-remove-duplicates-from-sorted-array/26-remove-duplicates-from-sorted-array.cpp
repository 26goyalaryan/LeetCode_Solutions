class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
            return n;
        int j=1;
        int i=0;
        while(j<n){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
                j++;
            }
            else
                j++;
        }
        return i+1;
    }
};