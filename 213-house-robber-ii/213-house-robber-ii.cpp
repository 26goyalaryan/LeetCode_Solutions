class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        int with_first=func(nums,0,nums.size()-1);
        int with_last=func(nums,1,nums.size());
        
        return max(with_first,with_last);
    }
    int func(vector<int> &nums,int start,int end){
        //vector<int> dp(n);
        int prev1=nums[start];
        int prev2=0;
        
        for(int i=start+1;i<end;i++)
        {
            int pick=nums[i];
            if(i>1)
                pick+=prev2;
            int nt_pick=prev1;

            int curri=max(pick,nt_pick);
            prev2=prev1;
            prev1=curri;
        }
        return prev1;
    }
};