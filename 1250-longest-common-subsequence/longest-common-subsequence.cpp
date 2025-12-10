class Solution {
public:
    int LCS(string &text1,string &text2,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i] == text2[j]){
            // i--;j--;
            return dp[i][j] = 1+LCS(text1, text2, i-1,j-1,dp);
        }
        return dp[i][j] = max(LCS(text1,text2,i-1,j,dp),LCS(text1,text2,i,j-1,dp));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        // int length = 0;
        // int i = text1.length()-1;
        // int j = text2.length()-1;
        // vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        // return LCS(text1,text2,i,j,dp);
        //Tabulation
        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1,0));
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
};