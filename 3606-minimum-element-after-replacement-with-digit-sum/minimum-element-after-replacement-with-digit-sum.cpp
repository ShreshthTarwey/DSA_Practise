class Solution {
public:
    int minElement(vector<int>& nums) {
        int minNum = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int res = 0;
            while(num){
                int digit = num%10;
                res += digit;
                num /= 10;
            }
            minNum = min(minNum, res);
        }
        return minNum;
    }
};