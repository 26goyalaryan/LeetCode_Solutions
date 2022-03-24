class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        // map to store anagrams after sorting.
        for(auto it:strs){
            string s=it;
            sort(s.begin(),s.end());
            mp[s].push_back(it);
        }
        vector<vector<string>> ans; 
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};