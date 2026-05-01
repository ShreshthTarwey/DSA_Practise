class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int f0 = 0;
        for(int i=0;i<n;i++){
            f0 += (i * nums[i]);
        }
        int ans = f0;
        for(int k=1;k<n;k++){
            int fk = f0 + sum - (n*nums[n-k]);
            ans = max(ans, fk);
            f0 = fk;
        }
        return ans;
    }
};