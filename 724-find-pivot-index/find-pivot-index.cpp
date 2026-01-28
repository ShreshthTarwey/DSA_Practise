class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int rightSum = 0;
        for(int i=0;i<nums.size();i++){
            rightSum = totalSum - nums[i] - leftSum;
            if(leftSum == rightSum){
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
    }
};