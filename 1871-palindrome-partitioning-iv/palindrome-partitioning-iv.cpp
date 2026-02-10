class Solution {
public:
    int dp[2000][2000];
    bool isPali(string &s, int i, int j){
        while(i<=j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    bool preCompute(string &s, int i, int j){
        if(i<0 || j<0 || i>=s.length() || j>=s.length()) return false;
        if(i>=j) return dp[i][j] = true;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = (s[i] == s[j]) && preCompute(s, i+1, j-1); 
    }
    bool checkPartitioning(string s) {
        int n = s.length();
        memset(dp, -1, sizeof dp);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                preCompute(s, i, j);
            }
        }
        for(int i=0;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                if(dp[0][i] && dp[i+1][j] && dp[j+1][n-1]){
                    return true;
                }
            }
        }
        return false;
    }
};