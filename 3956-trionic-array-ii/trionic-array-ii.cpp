class Solution {
public:
    typedef long long ll;
    ll recFun(vector<int>& nums, int index, int trend, vector<vector<ll>>& dp){
        if(index>=nums.size()){
            if(trend==3){
                return 0;
            }
            else{
                return LLONG_MIN;
            }
        }

        if(dp[index][trend]!=-1) return dp[index][trend];
        

        ll take = LLONG_MIN/2;
        ll notTake = LLONG_MIN/2;
        if(trend==0){
            // take = recFun(nums, index, 1);
            notTake = recFun(nums, index+1, 0, dp);
        }
        if(trend == 3){
            notTake = nums[index];
        }
        if(index+1<nums.size()){
            int curr = nums[index];
            int next = nums[index+1];
            if(trend == 0 && curr<next){
                take = max(take, curr + recFun(nums, index+1, 1, dp));
            }
            else if(trend==1 && curr<next){
                take = max(take,curr + recFun(nums, index+1, 1, dp));
            }
            else if(trend==1 && curr>next){
                take =  max(take, curr + recFun(nums, index+1, 2, dp));
            }

            else if(trend==2 && curr>next){
                // return curr + recFun(nums, index+1, 2);
                take = max(take, curr + recFun(nums, index+1, 2, dp));
            }
            else if(trend == 2 && curr<next){
                take = max(take, curr + recFun(nums, index+1, 3, dp));
            }
            else if(trend == 3 && curr<next){
                take = max(take, curr + recFun(nums, index+1, 3, dp));
            }
        }
        return dp[index][trend] = max(take, notTake);

    }
    ll maxSumTrionic(vector<int>& nums) {
        vector<vector<ll>>dp(nums.size(), vector<ll>(4, -1));
        return recFun(nums, 0, 0, dp);
    }
};