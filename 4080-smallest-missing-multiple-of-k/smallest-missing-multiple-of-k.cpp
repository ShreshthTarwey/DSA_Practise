class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto &it: nums){
            mp[it]++;
        }
        for(int i=k;i<500;i+=k){
            if(mp.find(i) == mp.end()){
                return i;
            }
        }
        return -1;
    }
};