class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        vector<int> sf(26,0),tf(26,0);
        for(auto it:s){
            sf[it-'a']++;
        }
        for(auto it:t)
            tf[it-'a']++;
        for(int i=0;i<26;i++){
            if(sf[i]!=tf[i])
                ans+=abs(sf[i]-tf[i]);
        }
        return ans;
    }
};