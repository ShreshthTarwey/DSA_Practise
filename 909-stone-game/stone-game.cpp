class Solution {
public:
    int recFun(vector<int>& piles, int i, int j, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int take_i = piles[i] + min(recFun(piles, i+2, j, dp), recFun(piles, i+1, j-1, dp));
        int take_j = piles[j] + min(recFun(piles, i+1, j-1, dp), recFun(piles, i, j-2, dp));
        return dp[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>>dp(piles.size(), vector<int>(piles.size(), -1));
        int p1 = recFun(piles, 0, piles.size()-1, dp);
        int sum = accumulate(piles.begin(), piles.end(), 0);
        int p2 = sum - p1;
        return p1>=p2;
        // return true;
    }
};