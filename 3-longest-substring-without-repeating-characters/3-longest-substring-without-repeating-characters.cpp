class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int i=0,j=0,ans=0;
        while(j<s.size()){
            if(st.count(s[j])==0){
                // the charchter isnt repeating.
                st.insert(s[j]);
                ans=max(ans,(int)st.size());
                j++;
            }else{
                st.erase(s[i]);
                i++;
                /*
                    a b c d e f a g h 
                    0 1 2 3 4 5 6 7 8
                    i             j
                    ans=6 
                    
                    we will remove from start bcz it is possible to have no repeating chars 
                    from i+1 ---> j ---> n-1
                */
            }
        }
        return ans;
    }
};