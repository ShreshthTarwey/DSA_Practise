class Solution {
public:
    int recFun(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] !=-1) return dp[i][j];
        int take_i = nums[i] + min(recFun(nums, i+2, j, dp), recFun(nums, i+1, j-1, dp));
        int take_j = nums[j] + min(recFun(nums, i+1, j-1, dp), recFun(nums, i, j-2, dp));

        return dp[i][j] = max(take_i, take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        //Method1 -----> Recursion Type 1
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), -1));
        int p1 = recFun(nums, 0, nums.size()-1, dp);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int p2 = sum - p1;
        return p1 >= p2;
    }
};