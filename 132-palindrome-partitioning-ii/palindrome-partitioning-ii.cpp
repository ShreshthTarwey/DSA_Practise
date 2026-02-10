class Solution {
public:
    int dpPali[2000][2000];
    bool isPalindrome(string &s, int i, int j){
        while(i<=j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    int recFun(string &s, int i, int j, vector<int>& dp){
        if(i>=s.length()) return 0;
        if(dpPali[i][j] == 1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        for(int k=i;k<=j;k++){
            if(dpPali[i][k]){
                ans = min(ans, 1 + recFun(s, k+1, j, dp));
            }
        }
        return dp[i] = ans;
    }
    bool preCompute(string &s, int i, int j){
        if(i<0 || i>=s.length() || j<0 || j>=s.length()) return false;
        if(i>=j) return dpPali[i][j] = true;
        if(dpPali[i][j] != -1) return dpPali[i][j];

        return dpPali[i][j] = (s[i] == s[j]) && preCompute(s, i+1, j-1);
    }
    int minCut(string s) {
        vector<int>dp(s.length(), -1);
        memset(dpPali, -1, sizeof dpPali);
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                preCompute(s, i, j);

            }
        }
        return recFun(s, 0, s.length()-1, dp);
    }
};