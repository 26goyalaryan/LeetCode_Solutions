class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        int n=s.size();
        bool dp[n+1][n+1];
        unordered_set<string> st;
        for(auto it:dict){
            st.insert(it);
        }
        for(int i=1;i<=n;i++)
        {
            int start=1;
            int end=i;
            while(end<=n)
            { // creating sliding window
                string temp= s.substr(start-1,i);
                if(st.find(temp)!=st.end())
                    dp[start][end]=true; // current string in window found in dict
                else
                {
                    bool flag=false;
                    for(int i=start;i<end;i++)
                    {
                        if(dp[start][i] && dp[i+1][end])
                        {
                            flag=true;
                            // checking every pair
                            // (1,1) & (2,5) and so on ....
                            // if any pair both of the wordbreaks , return true;
                            break;
                        }
                    }
                    dp[start][end]=flag;
                }
                start++;
                end++;
            }
        }
        return dp[1][n];
    }
};
/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        int n=s.size();
        map<string,bool> mp;
        for(auto it:dict){
            mp[it]=true;
        }
        return helper(mp,dict,s);
    }
private:
    bool helper(map<string,bool>& mp,vector<string>& dict,string s){
        if(s.size()==0)
            return true;
        
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            if(mp.find(temp)!=mp.end() && helper(mp,dict,s.substr(i+1)))
                return true;
        }
        return false;
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        vector<bool> dp(s.size()+1,0);
        if(s.size()==0)
            return true;
        int size=s.size();
        for(int i=0;i<s.size();i++){
            if(helper(s.substr(0,i+1),dict) && wordBreak(s.substr(i+1,size-i+1),dict))
                return true;
        }
        return false;
    }
private:
    bool helper(string s, vector<string>& dict){
        for(int i=0;i<dict.size();i++){
            if(s==dict[i])
                return true;
        }
        return false;
    }
};
*/