class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>leftPrefix(nums.size(),1);
        //Creating left prefi product
        for(int i=1;i<nums.size();i++){
            leftPrefix[i] = leftPrefix[i-1] * nums[i-1];
        }

        int R = 1;
        int index = nums.size();
        for(int i=nums.size()-1;i>=0;i--){
            leftPrefix[i] = leftPrefix[i] * R;
            R *= nums[i];
        }
        return leftPrefix;
    }
};