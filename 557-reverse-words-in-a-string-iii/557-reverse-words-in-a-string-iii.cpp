class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        
        for(int i=0;i<s.size();i++){
            if(i==s.size()-1){
                temp+=s[i];
                reverse(temp.begin(),temp.end());
                ans+=temp;
                break;
            }
            else if(s[i]==' '){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=s[i];
                temp="";
                
            }else
                temp+=s[i];
        }
        return ans;
    }
};