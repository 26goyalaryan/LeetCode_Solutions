class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int i=0;
        int maxsum=0;
        int currsum=0;
        for(int j=0;j<nums.size();j++){
            while(st.count(nums[j]))
                {
                    st.erase(nums[i]);
                    currsum-=nums[i];
                    i++;
                }
                st.insert(nums[j]);
                currsum+=nums[j];
                maxsum=max(maxsum,currsum);
        }
        return maxsum;
    }
};