class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            // since each element [1,n] so index [0,n-1]
            // thats why we subtract 1 from current no.
            
            // we use abs bcz may be the no. is previously negated, so we can't use it
            // as index, so we take abs to find index of element which we have to  negate
            
            int temp_ind=abs(nums[i])-1;
            
            nums[temp_ind]=-nums[temp_ind];
            
            // if no. is currently positive then it means it was previously negated
            if(nums[temp_ind]>0)
                ans.push_back(temp_ind+1);
        }
        return ans;
    }
};