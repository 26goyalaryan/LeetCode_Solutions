class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]=i;
        }
        stack<int> st;
        for(int i=0;i<nums2.size();i++){
            int curr=nums2[i];
            while(!st.empty() && curr>st.top()){
                int val=st.top();
                int idx=mp[val];
                ans[idx]=curr;
                st.pop();
            }
            if(mp.find(curr)!=mp.end())
                st.push(curr);
        }
        return ans;
    }
};