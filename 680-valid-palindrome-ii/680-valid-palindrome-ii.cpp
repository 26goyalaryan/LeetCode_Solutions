class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        int count=0;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return ispalindrome(s,i+1,j) || ispalindrome(s,i,j-1);
            }
        }
        return true;
    }
private:
    bool ispalindrome(string &s,int l,int r){
        int i=l,j=r;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};