class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int>mp;
        int target = nums.size()/2;
        for(auto it: nums){
            mp[it]++;
        }
        
        for(auto it: mp){
            if(target == it.second){
                return it.first;
            }
        }
        return 0;
    }
};