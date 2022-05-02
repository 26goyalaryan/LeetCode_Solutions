class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         
        // sort the given array in order to apply two-pointer
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        
        if(nums.size()<3)
            return ans;
        
        for(int i=0;i<nums.size()-2;i++){
            
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                // first time or after skipping duplicates
                int low=i+1,high=nums.size()-1;
                // sum is initialised to a in (b+c=-a)
                int sum=0-nums[i];
                
                while(low<high){
                    if(nums[low]+nums[high]==sum){
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[low]);
                        t.push_back(nums[high]);
                        ans.push_back(t);
                        
                // moving low and high till next diff value so that no duplicates
                        
                        while(low<high && nums[low]==nums[low+1])
                            low++;
                        
                        while(low<high && nums[high]==nums[high-1])
                            high--;
                        
                        low++;
                        high--;
                    }
                    // need gretare value then move to right.
                    else if(nums[low]+nums[high]<sum)
                        low++;
                    
                    else
                        high--;
                }
            }
        }
        return ans;
    }
};