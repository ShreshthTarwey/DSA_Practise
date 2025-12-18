class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp){

        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int maxLength =1 ;
        for(int i = index; i<nums.size();i++){
            if(nums[index]<nums[i]){
                int l = 1 + solve(nums, i, dp);
                maxLength = max(maxLength, l);
            }
            
        }

        return dp[index] =  maxLength;
    }
    int lengthOfLIS(vector<int>& nums) {
        // int ans = 0;
        // vector<int>dp(nums.size(), -1);
        // for(int i=0;i<nums.size();i++){
        //     ans = max(ans, solve(nums, i, dp));
        // }
        // return ans;

        //-----------------------TABULATION-----------------------------------------
        vector<int>dp(nums.size()+1, 1);
        for(int i=nums.size()-1;i>=0;i--){
            int maxLen = 1;
            for(int j=i;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    int l = 1 + dp[j];
                    maxLen = max(maxLen,l);
                }
            }
            dp[i] = maxLen;
            maxLen = 1;
        }
        return *max_element(dp.begin(), dp.end());

    }
};