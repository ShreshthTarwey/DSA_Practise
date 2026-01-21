class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans(nums.size(), 0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 && nums[i]>1){
                ans[i] = -1;
            }
            else if(nums[i] == 1){
                ans[i] = 0;
            }
            else{
                //Finding the first unset bit count from right
                int temp = nums[i];
                int count = 0;
                while(temp&1){
                    count++;
                    temp = temp>>1;
                }
                if(temp==0){
                    ans[i] = nums[i] - (1<<(count-1));
                }
                // now nums[i] was = ans + (1<<count), right use pen and paper to think, using that formula
                else
                ans[i] = nums[i] - (1<<(count-1));

            }
        }
        return ans;
    }
};