class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // long long sum = accumulate(nums.begin(), nums.end(), 0);
        int maxElement = *max_element(nums.begin(), nums.end());
        int minELement = *min_element(nums.begin(), nums.end());
        long long sum = maxElement - minELement;
        return 1ll * sum * k;
    }
};