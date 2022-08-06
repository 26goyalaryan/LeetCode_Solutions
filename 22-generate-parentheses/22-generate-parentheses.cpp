class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int cp=0,op=0;
        helper(ans,cp,op,n,"");
        return ans;
    }
    void helper(vector<string> &ans,int cp,int op,int n,string s){
        if(op==n && cp==n){
            ans.push_back(s);
            return;
        }
        
        if(op<n){
            //s+="(";
            helper(ans,cp,op+1,n,s+"(");
        }
        if(cp<op){
            //s+=")";
            helper(ans,cp+1,op,n,s+")");
        }
    }
};