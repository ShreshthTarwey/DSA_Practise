class Solution {
public:
    int recFun(vector<int>& nums, int index, vector<int>& dp){
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int pick = nums[index] + recFun(nums, index+2, dp);
        int notPick = 0;
        notPick = recFun(nums, index+1, dp);
        return dp[index] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        //MEMO-----
        // vector<int>dp(nums.size(), -1);
        // return recFun(nums, 0, dp);  

        //TABULATION_____------------
        vector<int>dp(nums.size()+2, 0);
        for(int i=nums.size()-1;i>=0;i--){
            int pick = nums[i] + dp[i+2];
            int notPick = dp[i+1];
            dp[i] = max(pick, notPick);
        }
        return dp[0];
    }
};