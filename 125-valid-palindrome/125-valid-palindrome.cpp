class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        for(i,j;i<j;i++,j--){
            while(isalnum(s[i])==false && i<j)
                // incerement i till you find next alphanumeric from front.
                i++;
            while(isalnum(s[j])==false && j>i)
                // decrement j till you find next alphanumeri from back
                j--;
            if(tolower(s[i])!=tolower(s[j]))
                // put a check if not equal ; return false
                return false;
        }
        return true;
    }
};