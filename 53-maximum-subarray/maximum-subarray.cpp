class Solution {
public:
    int brute(vector<int>&nums){
        int sum = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int sum2=0;
            for(int j=i;j<n;j++){
                sum2+=nums[j];
                sum=max(sum2,sum);
            }
        }
        return sum;
    }
    int kadnesAlgo(vector<int>&nums){//Very Important for interview
        int ans = INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0){
                sum=0;
            }
        }
            return ans;

    }     
    int dncMethod(vector<int>& nums, int left, int right){
        //Base Case
        if(left>right) return 0;

        if(left==right) return nums[left];

        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;

        int mid = left + (right-left)/2;

        int leftSum = dncMethod(nums, left, mid);

        int rightSum = dncMethod(nums, mid+1, right);

        //Max Cross Border Sum
        int leftBorderSum = 0, rightBorderSum = 0;
        for(int i=mid;i>=left;i--){
            leftBorderSum += nums[i];
            maxLeftBorderSum = max(maxLeftBorderSum, leftBorderSum);
        }

        for(int i = mid+1;i<=right;i++){
            rightBorderSum+= nums[i];
            maxRightBorderSum  = max(maxRightBorderSum, rightBorderSum);
        }

        int crossBorderSum = maxRightBorderSum + maxLeftBorderSum;

        return max(leftSum, max(rightSum, crossBorderSum));

    }
    int maxSubArray(vector<int>& nums) {
        // return brute(nums);
        // return kadnesAlgo(nums);
        return dncMethod(nums, 0, nums.size()-1);
    }

};