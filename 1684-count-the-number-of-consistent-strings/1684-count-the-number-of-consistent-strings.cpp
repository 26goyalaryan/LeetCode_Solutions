class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int s=words.size();
        vector<int> freq(26,0);
        for(char it:allowed){
            freq[it-'a']++;
        }
        for(auto it:words){
            for(char ch:it){
                if(freq[ch-'a']==0){
                    s--;
                    break;
                }
            }
        }
        return s;
    }
};