class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int temp=0;
        for(auto it:nums){
            temp+=it;
            ans.push_back(temp);
            
        }
        return ans;
    }
};