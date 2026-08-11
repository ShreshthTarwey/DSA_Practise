class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i = 1;
        int sum = nums[0];
        //Find the first break;
        while(i<nums.size() && nums[i-1] + 1 == nums[i]){
            sum += nums[i];
            i++;
        }

        unordered_set<int>st(nums.begin(), nums.end());
        while(st.count(sum)){
            sum++;
        }
        return sum;
    }
};