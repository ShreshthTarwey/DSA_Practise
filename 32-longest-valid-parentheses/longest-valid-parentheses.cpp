class Solution {
public:
    int stackMethod(string s){
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
    bool isValidParanthesis(string s){
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && s[st.top()]=='(' && s[i] == ')'){
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        return st.empty();
    }
    int recFun(int i, int j, string &s, vector<vector<int>>& dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(isValidParanthesis(s.substr(i, j-i+1))){
            ans = j-i+1;
        }
        int option1 = recFun(i+1, j, s, dp);
        int option2 = recFun(i, j-1, s, dp);
        return dp[i][j] = max(ans, max(option1, option2));
    }
    int dpMethod(string s){
        vector<vector<int>>dp(s.length(), vector<int>(s.length(), -1));
        return recFun(0,s.length()-1, s, dp);
    }
    int longestValidParentheses(string s) {
        return stackMethod(s);
        // return dpMethod(s);
    }
};