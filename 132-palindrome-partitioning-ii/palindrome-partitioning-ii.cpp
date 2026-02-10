class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<=j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    // int recFun(string &s, int i, int j, vector<vector<int>>& dp){
    //     if(isPalindrome(s, i, j)){
    //         return 0;
    //     }
    //     else{
    //         if(dp[i][j]!=-1) return dp[i][j];
    //         int ans = INT_MAX;
    //         for(int k=i;k<j;k++){
    //             int cost1 = recFun(s, i, k, dp);
    //             int cost2 = recFun(s, k+1, j, dp);
    //             ans = min(ans, 1 + cost1+cost2);
    //         }
    //         return dp[i][j] = ans;
    //     }
    // }
    int recFun2(string &s, int i, int j, vector<int>& dp){
        if(isPalindrome(s, i, j)) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(isPalindrome(s, i, k)){
                int cost = recFun2(s, k+1, j, dp);
                ans = min(ans, 1+cost);
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        // vector<vector<int>>dp(s.length(), vector<int>(s.length(), -1));
        // return recFun(s, 0, s.length()-1, dp); //TLE is Coming ------ 😓
        vector<int>dp(s.length(), -1);
        return recFun2(s, 0, s.length()-1, dp);
    }
};