class Solution {
public:
    int recFun(vector<int>& piles, int person, int idx, int M, vector<vector<vector<int>>>& dp){
        int n = piles.size();
        if(idx>=n){
            return 0;
        }
        if(dp[person][idx][M] != -1){
            return dp[person][idx][M];
        }
        int stones = 0;
        int result = (person == 1) ? -1 : INT_MAX;
        for(int x = 1;x<=min(2*M, n-idx);x++){
            stones += piles[idx+x-1];
            if(person == 1){ //Alice is playing ----> Take Best Choise
                result = max(result, stones + recFun(piles, 0, idx+x, max(M, x), dp));
            }
            else{ //Bob is playing -----> Assume worst
                result = min(result, recFun(piles, 1, idx+x, max(M, x), dp));
            }
        }
        return dp[person][idx][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>>dp(2, vector<vector<int>>(100, vector<int>(100, -1)));
        return recFun(piles, 1, 0, 1, dp);
    }
};