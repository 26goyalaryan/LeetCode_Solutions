class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0)
            return 0;
        // if the whole string is palindrome ----> return 1;
        // if not, there will always be 2 steps req to empty the string
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return 2;
            i++;
            j--;
        }
        return 1;
    }
};