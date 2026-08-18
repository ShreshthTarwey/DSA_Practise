class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        if(k==1){
            int ans = -1;
            for(auto &it: mp){
                if(it.second==1){
                    ans = max(ans, it.first);
                }
            }
            return ans;
        }
        else if(k==n){
            return *max_element(nums.begin(), nums.end());
        }
        else{
            if(mp[nums[n-1]] == 1 && mp[nums[0]] == 1){
                return max(nums[0], nums[n-1]);
            }
            else if(mp[nums[0]] == 1){
                return nums[0];
            }
            else if(mp[nums[n-1]] == 1){
                return nums[n-1];
            }
            else{
                return -1;
            }
        }
    }
};