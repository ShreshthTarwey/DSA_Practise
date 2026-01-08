class Solution {
public:
    int recFun(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp){
        if(i>=nums1.size() || j>=nums2.size()){
            return -1e9+7;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int mul = nums1[i] * nums2[j] + max(0,recFun(nums1, nums2, i+1, j+1, dp));
        int opt1 = recFun(nums1, nums2, i+1, j, dp);
        int opt2 = recFun(nums1, nums2, i, j+1, dp);
        return dp[i][j] = max(mul, max(opt1, opt2));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(), vector<int>(nums2.size(), -1));
        return recFun(nums1, nums2, 0, 0, dp);
    }
};