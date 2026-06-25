class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        int count = 0;
        int less = 0;
        int current = 0;
        mp[0] = 1;
        for(int i=0;i<nums.size();i++){
            int val = nums[i] == target ? 1 : -1;
            if(val == 1){
                current += 1;
                less += mp[current-1];
            }
            else{
                current -= 1;
                less -= mp[current];
            }
            count += less;
            mp[current]++;
        }
        return count;
    }
};