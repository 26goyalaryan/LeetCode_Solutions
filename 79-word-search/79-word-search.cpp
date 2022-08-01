class Solution {
public:
    bool exist(vector<vector<char>>& b, string word) {
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[i].size();j++){
                if(helper(b,i,j,word))
                    return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& b,int i,int j,string &word){
        if(word.size()==0)
            // this means we have reached the end of required word and found all the
            // charchters, so only case where we will return true;
            return true;
        if(i<0 || i>=b.size() || j<0 || j>= b[0].size() || b[i][j]!=word[0])
            
            // b[i][j]!=word[0] <--- we put this check since we ommit the char if we found 
            // and pass the substring from its next char to end.
            // so in any case if it doesn't match the b[i][j] we return false;
            
            return false;
        char temp=b[i][j];
        b[i][j]='#'; // since we can use only once so to avoid duplicacy
        
        string s=word.substr(1);
        bool res=helper(b,i,j-1,s) ||
                 helper(b,i,j+1,s) ||
                 helper(b,i+1,j,s) ||
                 helper(b,i-1,j,s);
        // backtracking step
        b[i][j]=temp; // put it back bcz this may be used in future iterations
        
        return res;
    }
};