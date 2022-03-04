class Solution {
public:
    int minSteps(string s, string t) {
        int count=0;
        vector<int> sf(26,0);
        vector<int> tf(26,0);
        for(auto it:s)
            sf[it-'a']++; // count the freq of characters in s.
        for(auto it:t)
            tf[it-'a']++; // count the freq of characters in s.
        for(int i=0;i<26;i++){
            count+=abs(sf[i]-tf[i]); 
            
            /* minimum count will be the total difference of frequency present in either of string
            eg in "arjun" & "aryan" or the same elements will cancel out each other and rest all will
            be returned.
            */
        }
        return count;
    }
};