class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto it:nums)
            st.insert(it);
        int ans=0;
        
        for(auto num:nums){
            if(!st.count(num-1)){
                int curr=num;
                int curr_ans=1;
                while(st.count(curr+1)){
                    curr+=1;
                    curr_ans++;
                }
                ans=max(ans,curr_ans);
            }
        }
        return ans;
    }
};