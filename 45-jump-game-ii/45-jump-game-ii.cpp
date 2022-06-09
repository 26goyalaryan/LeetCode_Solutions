class Solution {
public:
    int jump(vector<int>& nums) {
        int end=0,far=0,beg=0;
        int jump=0;
        int n=nums.size()-1;
        for(int i=0;i<nums.size()-1;i++){
            far=max(far,i+nums[i]); // how far can we go
            if(i==end){
                // if we reach end, ie no more calulation for farthest to be done
                jump++;
                beg=end;
                end=far;
            }
        }
        return jump;
    }
};