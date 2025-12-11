class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp){
        if(index<0) return 0;
        if(dp[index] != -1) return dp[index];
        int maxLength = 1;
        for(int j=index-1;j>=0;j--){
            if(nums[j]<nums[index]){
                int l = 1 + solve(nums, j, dp);
                maxLength = max(maxLength, l);
            }
        }
        return dp[index] = maxLength;
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0; vector<int> dp(nums.size(), -1);
        for(int i=0;i<nums.size();i++)
        ans = max(ans, solve(nums, i, dp));
       return ans;
    }
};