class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            int num = 0;
            bool flag = false;
            while(num<=nums[i]){
                if((num | num+1)==nums[i]){
                    ans[i] = num;
                    flag = true;
                    break;
                }
                num++;
            }
            if(!flag){
                ans[i] = -1;
            }
        }
        return ans;
    }
};