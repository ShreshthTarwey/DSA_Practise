class Solution {
public:
    int recFun(vector<vector<int>>& coins, int i, int j, int count, vector<vector<vector<int>>>& dp){
        int n = coins.size();
        int m = coins[0].size();
        if(i==n-1 && j==m-1){
            if(coins[i][j]<0 && count){
                return 0;
            }
            return coins[i][j];
        }
        if(dp[i][j][count]!= -1) return dp[i][j][count];
        int res = INT_MIN;
        if(i+1 < n){
            if(coins[i][j]<0 && count){
                res = max(res, recFun(coins, i+1, j, count-1, dp));
            }
            res = max(res, coins[i][j] + recFun(coins, i+1, j, count, dp));
        }
        if(j+1 < m){
            if(coins[i][j]<0 && count){
                res = max(res, recFun(coins, i, j+1, count-1, dp));
            }
            res = max(res, coins[i][j] + recFun(coins, i, j+1,count, dp));
        }
        return dp[i][j][count] = res;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        int count = 2;
        // vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(3, -1)));
        // return recFun(coins,  0, 0, count, dp); //Memoization gives TLE-----------------------------------
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));
        //Base Case filling
        for(int k=0;k<=2;k++){
            if(coins[n-1][m-1]<0 && k>0){
                dp[n-1][m-1][k] = 0;
            }
            else{
                dp[n-1][m-1][k]  = coins[n-1][m-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
                for(int k=2;k>=0;k--){
                    int res = INT_MIN;
                    if(i+1<n){
                        if(coins[i][j]<0 && k)
                            res = max(res, dp[i+1][j][k-1]);
                        res = max(res, coins[i][j] + dp[i+1][j][k]);
                    }
                    if(j+1<m){
                        if(coins[i][j]<0 && k){
                            res = max(res, dp[i][j+1][k-1]);
                        }
                        res = max(res, coins[i][j] + dp[i][j+1][k]);
                    }
                        dp[i][j][k] = res;
                }
            }
        }
        int ans = max({dp[0][0][0], dp[0][0][1], dp[0][0][2]});
        return ans;
    }
};