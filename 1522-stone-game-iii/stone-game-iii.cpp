class Solution {
public:
    int recFun(vector<int>& stoneValue, int idx, vector<int>& dp){
        if(idx>=stoneValue.size()){
            return 0;
        }
        if(dp[idx] != INT_MIN) return dp[idx];
        int opt1 = -9999;
        int opt2 = -9999;
        int opt3 = -9999;
        opt1 = stoneValue[idx] + min(recFun(stoneValue, idx+2, dp), min(recFun(stoneValue, idx+3, dp), recFun(stoneValue, idx+4, dp)));

        if(idx+1<stoneValue.size()){
            opt2 = stoneValue[idx] + stoneValue[idx+1] + min(recFun(stoneValue, idx+3, dp), min(recFun(stoneValue, idx+4, dp), recFun(stoneValue, idx+5, dp)));
        }
        if(idx+2<stoneValue.size()){
            opt3 = stoneValue[idx] + stoneValue[idx+1] + stoneValue[idx+2] + min(recFun(stoneValue, idx+4, dp), min(recFun(stoneValue, idx+5, dp), recFun(stoneValue, idx+6, dp)));
        }

        return dp[idx] = max(opt1, max(opt2, opt3));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        vector<int>dp(stoneValue.size(), INT_MIN);
        int p1 = recFun(stoneValue, 0, dp);
        int p2 = sum - p1;
        if(p1>p2){
            return "Alice";
        }
        else if(p1==p2){
            return "Tie";
        }
        else{
            return "Bob";
        }
    }
};