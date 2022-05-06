class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(0,s,res,path);
        return res;  
    }
public:
    void solve(int index,string s,vector<vector<string>> &res,vector<string> &path){
        if(index==s.size()){
            res.push_back(path); // base case if partition is to be done on last position.
            return;
        }
        for(int i=index;i<s.size();i++){
            if(ispalindrome(s,index,i))
            {
                path.push_back(s.substr(index,(i-index)+1));
                solve(i+1,s,res,path); 
                path.pop_back();
            }
        }
    }
public:
    bool ispalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
};