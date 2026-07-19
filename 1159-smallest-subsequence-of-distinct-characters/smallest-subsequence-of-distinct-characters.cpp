class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        vector<bool>taken(26, false);
        vector<int>lastSeen(26, 0);
        for(int i=0;i<s.length();i++){
            lastSeen[s[i] - 'a'] = i;
        }
        for(int i=0;i<s.length();i++){
            if(!taken[s[i] - 'a']){
                while(!st.empty() && st.top()>s[i] && lastSeen[st.top()-'a'] >i){
                    taken[st.top()-'a'] = false;
                    st.pop();
                }
                st.push(s[i]);
                taken[s[i] - 'a'] = true;
            }
        }
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};