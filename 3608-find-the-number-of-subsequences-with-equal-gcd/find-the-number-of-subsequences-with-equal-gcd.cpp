class Solution {
public:
    const int MOD = 1e9+7;
    int recFun(vector<int>& nums, int idx, int first, int second, vector<vector<vector<int>>>& dp){
        if(idx==nums.size()){
            if(first!=0 && second!=0 && first==second){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[idx][first][second] != -1) return dp[idx][first][second];
        int skip = recFun(nums, idx+1, first, second, dp);
        int take1 = recFun(nums, idx+1, gcd(first, nums[idx]), second, dp);
        int take2 = recFun(nums, idx+1, first, gcd(second, nums[idx]), dp);

        return dp[idx][first][second] = ((skip + take1)%MOD + take2)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(201, vector<int>(201, -1)));
        return recFun(nums, 0, 0, 0, dp);
    }
};