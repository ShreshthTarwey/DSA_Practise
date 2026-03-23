class Solution {
public:
    int recFun(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m){
            return 100000;
        }
        if(i==n-1 && j==m-1){
            return grid[n-1][m-1];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int opt1 = grid[i][j] + recFun(grid, i, j+1, dp);
        int opt2 = grid[i][j] +  recFun(grid, i+1, j, dp);

        return dp[i][j] = min(opt1, opt2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return recFun(grid, 0, 0, dp);
    }
};