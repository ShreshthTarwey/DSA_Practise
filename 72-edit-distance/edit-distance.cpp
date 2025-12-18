class Solution {
public:
    int recFun(string &word1, string &word2, int i, int j, vector<vector<int>>& dp){
        //BC
        if(j>=word2.length()) return word1.length() - i;
        if(i>=word1.length()) return word2.length() - j;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]){
            return recFun(word1, word2, i+1, j+1, dp);
        }

        int insert = 1 + recFun(word1, word2, i, j+1, dp);

        int del = 1 + recFun(word1, word2, i+1, j, dp);

        int replace = 1 + recFun(word1, word2, i+1, j+1, dp);

        return dp[i][j] = min(insert, min(del, replace));
    }
    int minDistance(string word1, string word2) {
        //Memoization
        vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1));
        return recFun(word1, word2, 0, 0, dp);
    }
};