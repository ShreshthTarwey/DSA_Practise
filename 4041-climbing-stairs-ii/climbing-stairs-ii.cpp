class Solution {
public:
    int recFun(vector<int>& costs, int n, int idx, vector<int>& dp){
        if(idx>n){
            return 1e9;
        }
        if(idx==n){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int ans = 1e9;
        for(int i=idx+1;i<idx+4;i++){
            if(i<=n)
            ans = min(ans, (i-idx) * (i-idx) + recFun(costs, n, i,dp) + costs[i-1]);
        }
        return dp[idx] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1, -1);
        return recFun(costs, n, 0, dp);
    }
};