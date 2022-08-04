class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // we will implement stack as an array
        // while we have element greater , we will keep adding as
        // we need a inceasing sequence and we pop if curr element greater
        // than top of stack
        
        vector<int> ans;
        
        // rem elements bcz we need to remove this much element in order to return k
        int rem_ele=nums.size()-k;
        
        for(auto it:nums)
        {
            
            // if curr element is smaller than top, ie we must not take curr_top
            while(rem_ele!=0 && ans.size()!=0 && it<ans.back()){
                ans.pop_back();
                rem_ele--;
            }
            ans.push_back(it);
        }
        while(rem_ele!=0){
            ans.pop_back();
            rem_ele--;
        }
        return ans;
    }
};