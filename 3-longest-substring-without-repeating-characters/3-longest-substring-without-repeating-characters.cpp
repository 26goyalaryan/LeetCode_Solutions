class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxi=0;
        int i=0,j=0;
        while(j<s.size())
        {
            if(st.count(s[j])==0)
            {
                st.insert(s[j]);
                maxi=max(maxi,(int)st.size());
                j++;
            }
            else
            {
                st.erase(s[i]); // removing the first charchter of the repeating string
                i++; 
            }
        }
        return maxi;
    }
};