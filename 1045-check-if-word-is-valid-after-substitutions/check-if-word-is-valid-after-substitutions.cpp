class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=s.length()-1;i>=0;i--){
            if(!st.empty() && s[i] == 'a'){
                if(st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top()=='c'){
                        st.pop();
                        continue;
                    }
                    else{
                        st.push('b');
                    }
                }
            }
            st.push(s[i]);
        }
        return st.empty();
    }
};