class Solution {
public:
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
        if(isPalindrome(s, i, j)) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        for(int k=i;k<=j;k++){
            if(isPalindrome(s, i, k)){
                ans = min(ans, 1 + recFun(s, k+1, j, dp));
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        vector<int>dp(s.length(), -1);
        return recFun(s, 0, s.length()-1, dp);
    }
};