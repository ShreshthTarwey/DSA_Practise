class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int player1Active = true;
        int sum1 = 0;
        int sum2 = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 != 0){
                player1Active = !player1Active;
            }
            if((i+1)%6==0){
                player1Active = !player1Active;
            }
            if(player1Active){
                sum1 += nums[i];
            }
            else{
                sum2 += nums[i];
            }
        }
        return sum1 - sum2;
    }
};