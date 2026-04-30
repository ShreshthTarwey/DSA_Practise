class Solution {
public:
    int recFun(vector<vector<int>>& grid, int i, int j, int c, int k, vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        int cost = 0;
        int score = 0;
        if(grid[i][j] == 1 || grid[i][j] == 2){
            cost = 1;
            if(grid[i][j] == 2){
                score+=2;
            }
            else{
                score += 1;
            }
        }
        if(dp[i][j][c] != -1) return dp[i][j][c];
        if(i==n-1 && j==m-1){
            if(cost + c <=k){
                return score;
            }
            else{
                return INT_MIN;
            }
        }
        int opt1 = INT_MIN;
        int opt2 = INT_MIN;
        if(cost + c <= k){
            if(j+1 < m){
                opt1 = score + recFun(grid, i, j+1, c + cost, k, dp);
            }
            if(i+1 < n){
                opt2 = score + recFun(grid, i+1, j, c + cost, k, dp);
            }
        }
        return dp[i][j][c] = max(opt1, opt2);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>>dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k+1, -1)));
        int ans = recFun(grid, 0, 0, 0, k, dp);
        if(ans < 0){
            return -1;
        }
        return ans;
    }
};