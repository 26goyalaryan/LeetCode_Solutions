class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pi=0,ni=1;
        //pi is used for positive index
        //ni is used for negative index
        for(auto it:nums){
            if(it>0){
                ans[pi]=it; 
                // insert positive element at pi
                // shift pi to 2 positions as we have to maintain
                // (positive negative) pair.
                pi+=2;
            }
            else{
                ans[ni]=it;
                ni+=2;
            }
        }
        return ans;
    }
};