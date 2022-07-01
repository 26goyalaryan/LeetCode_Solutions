class Solution {
public:
    string greatestLetter(string s) {
        vector<int> up(26,0),lo(26,0);
        string ans="";
        for(auto it:s){
            if(it-'a'>=0 && it-'z'<=26)
                lo[it-'a']++;
            else if(it-'A'>=0 && it-'Z'<=26)
                up[it-'A']++;
        }
        for(int i=25;i>=0;i--){
            if(lo[i] && up[i]) 
            
            //if char found in upp and low together
            {
                ans+='A'+i;
                // pushing the element in uppercase and break loop.
                break;
            }
        }
        return ans;
    }
};