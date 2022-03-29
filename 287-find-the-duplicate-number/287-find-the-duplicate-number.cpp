class Solution {
public:
    // we can solve it using flyod cycle algorithm
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n>1){
            int slow=nums[0],fast=nums[nums[0]];
            while(slow!=fast){
                slow=nums[slow];
                fast=nums[nums[fast]];
            }
            // the will meet somewhere in loop.
            // and when fast starts from 0 and slow moves in loop
            // they will again meet at loops starting point
            fast=0;
            while(slow!=fast){
                slow=nums[slow];
                fast=nums[fast];
            }
            return slow;
        }
        return -1; // if not found
    }
};