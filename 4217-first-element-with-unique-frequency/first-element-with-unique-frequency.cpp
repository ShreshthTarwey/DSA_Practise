class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        unordered_map<int, int>uniqueFreq;
        for(auto it: mp){
            uniqueFreq[it.second]++;
        }
        for(int i=0;i<nums.size();i++){
            if(uniqueFreq[mp[nums[i]]]==1){
                return nums[i];
            }
        }
        return -1;
    }
};