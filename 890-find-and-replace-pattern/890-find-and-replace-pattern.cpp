class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string pat=helper(pattern);
        
        vector<string> ans;
        
        for(int i=0;i<words.size();i++){
            string temp=helper(words[i]);
            if(temp==pat)
                ans.push_back(words[i]);
        }
        return ans;
    }
    string helper(string pattern){
        string ans="";
        
        unordered_map<char,char> mp;
        int j=0; // to indicate how many different chars are there.
        
        for(auto it:pattern){
            if(mp.find(it)==mp.end()) 
            // new char so to be mapped to new corresponding char    
            {
                mp[it]='a'+j;
                j++;
            }
            ans+=mp[it];
        }
        return ans;
    }
};