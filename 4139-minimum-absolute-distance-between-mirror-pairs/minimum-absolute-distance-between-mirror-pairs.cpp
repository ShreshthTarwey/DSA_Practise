class Solution {
public:
    int reverse(int n){
        int res = 0;
        while(n){
            int digit = n%10;
            res = res*10 + digit;
            n/=10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int>mp;
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                ans = min(ans, i - mp[nums[i]]);
            }
            mp[reverse(nums[i])] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};