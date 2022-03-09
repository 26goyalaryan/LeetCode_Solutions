class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        path_add(0,s,res,path);
        return res;  
    }
public:
    void path_add(int index,string s,vector<vector<string>> &res,vector<string> &path){
        if(index==s.size()){
            res.push_back(path); // base case if partition is to be done on last position.
            return;
        }
        for(int i=index;i<s.size();i++){
            if(ispalindrome(s,index,i)) // if palindrome , then only call function otherwise do not partition.
                // check if substring from index to i , ie left part of partition
                // eg- aa|bb ; here "aa" is to be checked.
            {
                path.push_back(s.substr(index,(i-index)+1));
                path_add(i+1,s,res,path); // will iterate over index to s.size(), to check every possible partition
                path.pop_back(); // backtrack and remove the string and partiton added.
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