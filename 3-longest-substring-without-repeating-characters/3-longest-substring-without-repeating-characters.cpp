class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        int left=0,right=0;
        int n=s.size();
        int ans=0;
        while(right<n){
            if(mp[s[right]]!=-1)
                left=max(mp[s[right]]+1,left);
            // updating left if repeation lies in (left-right)
            mp[s[right]]=right; 
            //storing the index;
            ans=max(ans,right-left+1); //len of window
            right++;
        }
        return ans;
    }
};