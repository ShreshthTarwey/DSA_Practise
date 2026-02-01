class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int cost = nums[0];
        int minElement = 100;
        int secondMin = 100;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=minElement){
                // if(secondMin>minElement)
                secondMin = minElement;
                minElement = nums[i];
            }
            else if(nums[i]>minElement && nums[i]<secondMin){
                secondMin = nums[i];
            }
        }
        return cost + minElement + (secondMin==100 ? 0 : secondMin);
    }
};