class Solution {
public:
    int asciiCal(string s, int index){
        int sum = 0;
        for(int i=index;i<s.length();i++){
            sum+= s[i];
        }
        return sum;
    }
    int recFun(string &s1, string &s2, int i, int j, vector<vector<int>>& dp){
        if(i>=s1.length()){
            return asciiCal(s2, j);
        }
        if(j>=s2.length()){
            return asciiCal(s1, i);
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = recFun(s1, s2, i+1, j+1, dp);
        }
        int opt1 = s1[i] + recFun(s1, s2, i+1, j, dp);
        int opt2 = s2[j] + recFun(s1, s2, i, j+1, dp);

        return dp[i][j] = min(opt1, opt2);
    }
    int minimumDeleteSum(string s1, string s2) {
        // Memoization----------------------------------------
        // vector<vector<int>>dp(s1.length(), vector<int>(s2.length(), -1));
        // return recFun(s1, s2, 0, 0, dp);
        // Tabulaization---------------------------------------------------------
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        //Base Case
        for(int j=0;j<m;j++){
            dp[n][j] = asciiCal(s2, j);
        }
        for(int i=0;i<n;i++){
            dp[i][m] = asciiCal(s1, i);
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                    continue;
                }
                int opt1 = s2[j] +  dp[i][j+1];
                int opt2 = s1[i] + dp[i+1][j];
                dp[i][j] = min(opt1, opt2);
            }
        }
        return dp[0][0];
    }
};