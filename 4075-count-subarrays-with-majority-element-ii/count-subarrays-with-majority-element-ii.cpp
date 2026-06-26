class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<long long, int>mp;
        int less = 0;
        int current = 0;
        long long count = 0;
        mp[0] = 1;
        for(auto &it: nums){
            int val = it == target ? 1 : -1;
            if(val == 1){
                current++;
                less += mp[current-1];
            }
            else{
                current--;
                less -= mp[current];    
            }
            mp[current]++;
            count += less;
        }
        return count;   
    }
};