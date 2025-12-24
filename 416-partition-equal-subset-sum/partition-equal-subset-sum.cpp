class Solution {
public:
    bool recFun(vector<int>& nums, int index, int target, int sumTillNow, vector<vector<int>>& dp){
        if(index>=nums.size()) return false;
        if(sumTillNow==target) return true;
        if(dp[index][sumTillNow]!=-1) return dp[index][sumTillNow];
        bool pick = recFun(nums, index+1, target, sumTillNow+nums[index], dp);
        bool notPick = recFun(nums, index+1, target, sumTillNow, dp);
        return dp[index][sumTillNow] = (pick || notPick);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // if((sum&1)==0){
        //     vector<vector<int>>dp(nums.size()+1, vector<int>(sum+1, -1));
        // return recFun(nums, 0, sum/2, 0, dp);
        // }
        
        // return false;


        //TABULASIATION----------------------------------------------------------------------------------------------------------------
        if((sum&1)!=0) return false;

        vector<vector<int>>dp(nums.size()+1, vector<int>(sum+1, 0));
        for(int i=0;i<=nums.size();i++){
            dp[i][(sum/2)] = 1;
        }

        for(int i=nums.size()-1;i>=0;i--){
            for(int j=sum;j>=0;j--){
                bool pick = false;
                if(j+nums[i]<=sum)
                    pick = dp[i+1][j+nums[i]];
                bool notPick = dp[i+1][j];
                dp[i][j] = (pick || notPick);
            }
        }
        return dp[0][0];
    }
};