class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // return nums[0] + nums[nums.size()-1];
        int minSum = INT_MIN;
        int i = 0;
        int j = nums.size()-1;
        while(i<=j){
            int sum = nums[i++] + nums[j--];
            minSum = max(minSum, sum);
        }
        return minSum;
    }
};