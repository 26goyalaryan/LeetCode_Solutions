class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // we will be maintaining the length of out subseq in res vector
        
        // check for lower bound in res
        
        // if lb == end ---> res.push (nums[i])
        
        // else *lb = nums[i];
        
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++) {
        
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        
            if(it==res.end()) 
                
                res.push_back(nums[i]);
        
            else *it = nums[i];
        }
        
        return res.size();
    }
};
   