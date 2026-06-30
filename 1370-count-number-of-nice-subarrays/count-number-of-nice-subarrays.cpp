class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int oddCount = 0;
        int ans = 0;
        mp[oddCount]++;
        for(auto &it: nums){
            if(it%2!=0){
                oddCount++;
            }
            mp[oddCount]++;
            if(mp.find(oddCount - k) != mp.end()){
                ans += mp[oddCount - k];
            }
        }
        return ans;
    }
};