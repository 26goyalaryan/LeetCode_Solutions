/*
the all lexographical permutations follow a rule
it linearly increases from back till a break point. even a single element.

step1- we have to find break point.
step2-  we again traverse from back and swap with tha first greater with element at
        break point.
step3- we know that after break point, the string increases linearly, we just have to             reverse it so as to lower its rank.

 eg: 1 3 5 4 2
 step1: we find break point at 5;
 step2: we swap 3 with next greater than 3 ie 4.
 step3: we reverse from 2th index till last.
 so ans become "1 4 2 3 5".
 
               ^
eg:         5   \
          3   4  \
        1       2 \
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),k,l;
        // step:1 to find breakpoint.
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0)
            reverse(nums.begin(),nums.end());
        // edge case of 54321 where no break point.
        // so we directly return the first permutation.
        else{
            // step:2 to find next greater
            for(l=n-1;l>k;l--){
                if(nums[k]<nums[l])
                    break;
            }
            // step:3 swap and reverse.
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};