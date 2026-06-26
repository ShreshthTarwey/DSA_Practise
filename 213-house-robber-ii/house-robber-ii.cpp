class Solution {
public:
    int SirMethod(vector<int> &nums, int start, int end, vector<int>&dp ){
        if(start>end){
            return 0;
        }
        if(dp[start] != -1) return dp[start];

        int option1 = nums[start] + SirMethod(nums, start+2, end, dp);

        int option2 = SirMethod(nums, start+1, end, dp);

        return dp[start] = max(option1, option2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        //Handling case for single element -- yeh mai bhul gaya tha


        if(n==1) return nums[0];
        
        vector<int>dp(n+1, -1);
        int option1  = SirMethod(nums, 0, n-2, dp);
        dp.assign(n+1, -1);
        int option2 = SirMethod(nums, 1,n-1, dp);

        return max(option1, option2);


    }
};