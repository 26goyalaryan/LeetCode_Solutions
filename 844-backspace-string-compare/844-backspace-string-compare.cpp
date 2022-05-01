class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int j=0,i=0;
        for(int q=0;q<s.size();q++){
            if(s[q]=='#'){
                j--;
                j=max(0,j);
                 // j can never be negative, if all are backspace then at min it can be 0
            }
            else{
                s[j]=s[q];
                // this step will copy same elemnt 
                // but if '#' is encountered, it will move back and
                // replace the next element then '#' to jth index.
                j++;
            }
        }
        for(int q=0;q<t.size();q++){
            if(t[q]=='#'){
                i--;
                i=max(0,i);
            }
            else{
                t[i]=t[q];
                i++;
            }
        }
        
        // if i and j are at different index --> strings aren;t same after modification
        if(i!=j)
            return false;
        else{
            for(int q=0;q<i;q++){
                if(s[q]!=t[q])
                    return false;
            }
            return true;
        }
    }
};