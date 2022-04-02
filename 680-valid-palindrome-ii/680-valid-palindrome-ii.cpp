class Solution {
    /*
        if element from start and end we will keep traversing
        else
            
        case1: the string is palindrome from i+1--->j ie ith character is to be removed.
        case2: the palindrome lies b/w i-->j-1 ie jth character isnt valid
        
        else if both the cases return false ie there are more than one pair for the same
            we will return false;
            
    */
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        int count=0;
        while(i<=j){
           if(s[i]==s[j]){
               i++;
               j--;
           }else{
               return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
           }
        }
        return true;
    }
    bool isPalindrome(string &s,int l,int r){
        int i=l,j=r;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
};