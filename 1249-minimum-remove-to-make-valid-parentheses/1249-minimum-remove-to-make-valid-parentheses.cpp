class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        // to store the indexes of opening parentheses
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(i);
            // pushing index where there is any '('
            else if(s[i]==')')
                // stack is empty ie there is extra ')'.
                if(st.empty()){
                    s[i]='#';
                }
            else
                st.pop();
            // if stack is not empty and we encounter a ')'.
        }
        // if still stack is not empty ie there is/are extra '('.
        while(!st.empty()){
            s[st.top()]='#';
            st.pop();
        }
        // push all the characters other than # to return original string
        string ans;
        for(auto it:s){
            if(it!='#')
                ans.push_back(it);
        }
        return ans;
    }
};