class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());
        if(n != maxElement + 1){
            return false;
        }
        unordered_map<int, int>mp;
        for(auto &it: nums){
            mp[it]++;
        }
        if(mp[maxElement]!=2){
            return false;
        }
        for(int i=1;i<=maxElement;i++){
            if(mp.find(i) == mp.end()){
                return false;
            }
        }
        return true;
        
    }
};