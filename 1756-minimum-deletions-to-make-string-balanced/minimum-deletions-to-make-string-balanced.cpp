class Solution {
public:
    // stack<char>st;
    int recFun(string &s, int index, string temp, vector<int>& dp){
        if(index>=s.length()){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        if(temp==""){
            return dp[index] = recFun(s, index+1, temp+s[index], dp);
        }
        int option1 = INT_MAX;
        int option2 = INT_MAX;
        if(temp.back() == 'b' && s[index] == 'a'){
            temp.pop_back();
            option1 = 1 + recFun(s, index, temp, dp);
            temp.push_back('b');
            option2 = 1 + recFun(s, index+1, temp, dp);
            return dp[index] = min(option1, option2);
        }
        else{
            return dp[index] = recFun(s, index+1, temp+s[index], dp);
        }
        
    }
    int method2Stack(string s){
        stack<char>st;
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(st.top() == 'b' && s[i] == 'a'){
                count++;
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        return count;
    }
    int minimumDeletions(string s) {
        // vector<int>dp(s.length(), -1);
        // return recFun(s, 0, "", dp); //Cannot Apply DP here, and it was giving TLE, in recursion

        return method2Stack(s);

        
    }
};