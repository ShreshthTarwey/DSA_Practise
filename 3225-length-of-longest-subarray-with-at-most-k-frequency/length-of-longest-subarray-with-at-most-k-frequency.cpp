class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        unordered_map<int, int>mp;
        int n = nums.size();
        int ans = INT_MIN;
        while(j<n){
            if(mp[nums[j]]==k){
                while(i<=j && mp[nums[j]] == k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            mp[nums[j]]++;
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};