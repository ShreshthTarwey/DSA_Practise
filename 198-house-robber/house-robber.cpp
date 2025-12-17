class Solution {
public:
    int recurFun(vector<int>& nums, int index, vector<int>& dp){
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int pick = nums[index] + recurFun(nums, index+2, dp);
        int notPick = recurFun(nums, index+1, dp);
        return dp[index] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return recurFun(nums, 0, dp);
    }
};