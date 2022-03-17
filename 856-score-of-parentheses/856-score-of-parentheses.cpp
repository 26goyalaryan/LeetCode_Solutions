class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int count=0;
        for(auto it:s){
            if(it=='('){
                st.push(count);
                count=0;
                // everytime we go nested.
            }
            else
                {
                    count=st.top()+max(count*2,1);
                    st.pop();
                }
        }
        return count;
    }
};