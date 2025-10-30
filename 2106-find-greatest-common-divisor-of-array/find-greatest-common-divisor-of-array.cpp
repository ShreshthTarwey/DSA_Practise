class Solution {
public:
    int GCD(int x, int y){
        if(y==0) return x;
        return GCD(y,x%y);
    }
    int findGCD(vector<int>& nums) {
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxNum){
                maxNum = nums[i];
            }
            if(nums[i]<minNum){
                minNum = nums[i];
            }
        }
        return GCD(maxNum, minNum);
    }
};