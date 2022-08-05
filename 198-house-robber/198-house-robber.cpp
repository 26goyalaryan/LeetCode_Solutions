class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        //vector<int> dp(n);
        int prev1=nums[0];
        int prev2=0;
        
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1)
                pick+=prev2;
            int nt_pick=prev1;

            int curri=max(pick,nt_pick);
            prev2=prev1;
            prev1=curri;
        }
        return prev1; //max(pick,nt_pick);
    }
};