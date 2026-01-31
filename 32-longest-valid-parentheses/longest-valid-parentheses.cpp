class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int len = 0;
        for(int i=0;i<s.length();i++){
            if(st.top()!=-1 && s[st.top()]=='(' && s[i]==')'){
                st.pop();
                len = max(len, i-st.top());
                continue;
            }
            st.push(i);
        }
        return len;
    }
};