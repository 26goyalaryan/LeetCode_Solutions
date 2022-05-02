class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int streak=0,curr=0;
        for(auto it:nums){
            if(it==1)
                curr++;
            else{
                streak=max(streak,curr);
                curr=0;
            }
        }
        return max(streak,curr);
    }
};