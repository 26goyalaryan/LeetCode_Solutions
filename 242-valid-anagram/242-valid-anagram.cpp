class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sf(26,0),tf(26,0);
        for(auto it:s){
            sf[it-'a']++;
        }
        for(auto it:t)
            tf[it-'a']++;
        for(int i=0;i<26;i++){
            if(sf[i]!=tf[i])
                return false;
        }
        return true;
    }
};