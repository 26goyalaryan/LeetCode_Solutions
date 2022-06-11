class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        /*
            we convert this problem into a sliding window 
            we will find a subarray with 
                
                sum = totalsum-x;
            and this subarray, we will try to maximise the length of this subarray bcz 
            we want minimal elements == x.
            
            eg:     3  2  20  1  1  3 , x=10;
                         |___|
                    so subarray with maxlen and sum == target is 20
                     s0 ans => 6-1 = 5 
                     
            initiall we will take 2 variables i,j at 0th index.
            now keep moving j and add sum to curr_sum.
            
            if currsum == target at anystep. calculate the maxlength by (j-i+1).
            
            and if currsum>target, keep shinkring window and increment i.
        */
        
        int n=nums.size();
        int maxlen=0;
        int totalsum=0;
        int flag=0;
        for(auto it:nums){
            totalsum+=it;
        }
        int target=totalsum-x;
        int currsum=0;
        int i=0,j=0;
        for(int j=0;j<n;j++){
            currsum+=nums[j];
            while(i<=j && currsum>target){
                currsum-=nums[i];
                i++;
            }
            if(currsum==target){
                flag=1;
                maxlen=max(maxlen,j-i+1);
            }
        }
        return flag==1?n-maxlen:-1;
    }
};