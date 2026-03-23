class Solution {
public:
    typedef long long ll;
    pair<ll, ll> recFun(vector<vector<int>>& grid, int i, int j, vector<vector<pair<ll, ll>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i==n-1 && j==m-1){
            return {grid[i][j], grid[i][j]};
        }
        auto it = dp[i][j];
        if(it.first != -5 && it.second != -5) return it;
        ll minVal = LLONG_MAX;
        ll maxVal = LLONG_MIN;

        if(i+1<n){
            auto it = recFun(grid, i+1, j, dp);
            maxVal = max({maxVal, grid[i][j]*it.first, grid[i][j] * it.second});
            minVal = min({minVal, grid[i][j]*it.first, grid[i][j] * it.second});
        }
        if(j+1<m){
            auto it = recFun(grid, i, j+1, dp);
            maxVal = max({maxVal, grid[i][j]*it.first, grid[i][j] * it.second});
            minVal = min({minVal, grid[i][j]*it.first, grid[i][j] * it.second});
        }
        return dp[i][j] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pair<ll, ll>p = {-5, -5};
        vector<vector<pair<ll,ll>>>dp(n, vector<pair<ll, ll>>(m, p));
        auto it = recFun(grid, 0, 0, dp);
        // return (it.first<0 ? -1 : it.first);
        if(it.first<0) return -1;
        const int MOD = 1e9+7;
        return it.first % MOD;
    }
};