class Solution {
public:
    bool isAnagram(string s, string t) {
        char fs[26]={0};
        char ft[26]={0};
        for(auto it:s){
            fs[it-'a']++;
        }
        for(auto it:t){
            ft[it-'a']++;
        }
        for(int i=0;i<26;i++){
            if(fs[i]!=ft[i])
                return false;
        }
        return true;
    }
};