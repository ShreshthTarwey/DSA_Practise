class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>>dp(zero+1, vector<vector<int>>(one+1, vector<int>(2, 0)));
        for(int i=0;i<=min(limit, one);i++){
            dp[0][i][1] = 1;
        }
        for(int i=0;i<=min(limit, zero);i++){
            dp[i][0][0] = 1;
        }
        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){
                if(i==0 || j==0) continue;
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1])%MOD;
                if(j-1>=limit){
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j-1-limit][0] + MOD) %MOD;
                }
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
                if(i-1>=limit){
                    dp[i][j][0] = (dp[i][j][0] - dp[i-1-limit][j][1] + MOD) % MOD;
                }  
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};