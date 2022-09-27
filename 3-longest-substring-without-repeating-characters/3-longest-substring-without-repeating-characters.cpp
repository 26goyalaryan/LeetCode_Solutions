class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0, j = 0;
        unordered_set<char> st;
        int size = s.size();
        while (j < size)
        {
            if (!st.count(s[j]))
            {
                st.insert(s[j]);
                ans = max(ans, (int)st.size());
                j++;
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};