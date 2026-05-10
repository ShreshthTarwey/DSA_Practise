class Solution {
public:
    int recFun(vector<int>& nums, int target, int idx, vector<int>& dp){
        int n = nums.size();
        if(idx==n-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int steps = INT_MIN;
        for(int i=idx+1;i<n;i++){
            if(abs(nums[idx] - nums[i])<=target){
                steps = max(steps, 1 + recFun(nums, target, i, dp));
            }
        }
        return dp[idx] = steps;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size(), -1);
        int steps = recFun(nums, target, 0, dp);
        return steps < 0  ? -1 : steps; 
    }
};