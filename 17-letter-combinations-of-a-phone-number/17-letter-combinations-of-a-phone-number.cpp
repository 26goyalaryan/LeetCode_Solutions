class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>> mp;
        vector<string> ans;
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
        if(digits.size()==0)
            return {};
        vector<int> temp;
        for(auto it:digits){
            temp.push_back(it-'0');
        }
        solve(0,"",temp,ans,mp);
        return ans;
    }
    void solve(int ind,string s,vector<int> &temp,vector<string>                                    &ans,unordered_map<int,vector<char>> &mp){
        
        vector<char> t=mp[temp[ind]];
        for(char it:t){
            if(ind==temp.size()-1){
                ans.push_back(s+it);
            }else
                solve(ind+1,s+it,temp,ans,mp);
        }
    }
};