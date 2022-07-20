class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n=s.size();
        if(n==1)
            return s[0];
        string ans="";
        sort(s.begin(),s.end());
        string a=s[0],b=s[n-1];
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])
                break;
            ans+=a[i];
        }
        return ans;
    }
};