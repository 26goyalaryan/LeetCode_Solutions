class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0;
        int j=n;
        int temp=2*n;
        vector<int> ans;
        while(j<temp){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;j++;
        }
        return ans;
    }
};