class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int,int> am; // availability map for available elements
            
        unordered_map<int,int> vm; // vacancy map for next element that can be added
        
        for(auto it:nums)
            am[it]++;
        
        for(int i=0;i<nums.size();i++){

            if(am[nums[i]]<=0)
                continue;
            else{
                    // First check if it can fit into existing group
                if(vm[nums[i]]){

                    vm[nums[i]]--;
                    vm[nums[i]+1]++;
                }
                    // Then only check for the possibility of creating a new group
                else 
                    {
                        if(am[nums[i]+1]>0 && am[nums[i]+2]>0){

                        am[nums[i]+1]--;
                        am[nums[i]+2]--;

                        vm[nums[i]+3]++; 
                    }
                    else
                        return false;
                }
            }
            am[nums[i]]--;
        }
        return true;
    }
};