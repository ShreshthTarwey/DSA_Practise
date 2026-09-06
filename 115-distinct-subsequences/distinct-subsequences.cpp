class Solution {
public:
    int recFun(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j == t.length()) {
            return 1;
        }
        if (i == s.length()) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int opt1 = 0;
        int opt2 = 0;
        int opt3 = 0;
        if (s[i] != t[j]) {
            return recFun(s, t, i + 1, j, dp);
        }
        // Case A
        opt1 = recFun(s, t, i + 1, j + 1, dp);
        // Case B
        opt2 = recFun(s, t, i + 1, j, dp);

        return dp[i][j] = opt1 + opt2;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.length(), vector<int>(t.length(), -1));
        return recFun(s, t, 0, 0, dp);
    }
};