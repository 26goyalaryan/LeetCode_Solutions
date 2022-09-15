class Solution {
public:
    vector<int> findOriginalArray(vector<int>& chd) {
        
        int size=chd.size();
        
        if(size%2)
            return {};
        
        vector<int> ans;
        
        unordered_map<int,int> mp;
        
        sort(chd.begin(),chd.end());
        
        for(auto it:chd)
            mp[it]++;
        
        for(int i=0;i<size;i++){
            
            if(mp[chd[i]]==0)
                continue;
            
            if(mp[chd[i]*2]==0)
                return {};
            
            ans.push_back(chd[i]);
            
            mp[chd[i]]--;
            
            mp[chd[i]*2]--;
        }
        
        return ans;
    }
};