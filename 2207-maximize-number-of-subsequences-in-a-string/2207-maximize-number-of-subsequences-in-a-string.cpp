class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ansS=0,ansE=0;
        string s=pattern[0]+text;
        string e=text+pattern[1];
        long long count=0;
        for(auto it:s){
            if(it==pattern[0]){
                count++;
            }else if(it==pattern[1]){
                ansS+=count;
                // aaabb--> aaa can pair with b at 3 and 4 also.
            }
        }
        if(pattern[0]==pattern[1])
            // then our ans will remain 0 but still we can have subsequences
            /*
            eg- aaabb, aa
            0,1,2 ---> a can form subsequences.
            */
            ansS=(count*(count-1))/2;
        count=0;
        for(int i=e.size()-1;i>=0;i--){
            if(e[i]==pattern[1]){
                count++;
            }else if(e[i]==pattern[0]){
                ansE+=count;
                // aabbb--> bbb can pair with a at 0 and 1 also.
            }
        }
        if(pattern[0]==pattern[1])
            ansE=(count*(count-1))/2;
        return max(ansS,ansE);
    }
};