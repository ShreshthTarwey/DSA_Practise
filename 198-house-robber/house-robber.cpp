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
        // vector<int>dp(nums.size()+1, -1);
        // return recurFun(nums, 0, dp); //Memoization -----------------------------------------
        //Tabulation -------------------------------------------
        vector<int>dp(nums.size()+2, 0);
        for(int i=nums.size()-1;i>=0;i--){
            int pick = nums[i] + dp[i+2];
            int notPick = dp[i+1];
            dp[i] = max(pick, notPick);   
        }

        return dp[0];

    }
};