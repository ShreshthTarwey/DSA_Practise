class Solution {
public:
    long long recFun(vector<int>& nums, vector<int>& colors, int idx, bool isPrevPicked, vector<vector<long long>>& dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx][isPrevPicked]!=-1) return dp[idx][isPrevPicked];
        long long pick = LLONG_MIN;
        long long notPick = LLONG_MIN;
        if(!isPrevPicked || colors[idx] != colors[idx-1]){
            pick = nums[idx] + recFun(nums, colors, idx+1, true, dp);
        }
        notPick = recFun(nums, colors, idx+1, false, dp);

        return dp[idx][isPrevPicked] = max(pick, notPick);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<vector<long long>>dp(nums.size(), vector<long long>(2, -1));
        return recFun(nums, colors, 0, 0, dp);
    }
};