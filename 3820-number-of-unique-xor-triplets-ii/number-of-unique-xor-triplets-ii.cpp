class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int limit = 1;
        while (limit <= maxEle) {
            limit <<= 1;
        }
        vector<bool> pairXor(limit, false);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }
        vector<bool> tripleXor(limit, false);
        for (int i = 0; i < limit; i++) {
            if (pairXor[i]) {
                for (int x : nums) {
                    tripleXor[i ^ x] = true;
                }
            }
        }
        int count = 0;
        for (int val = 0; val < limit; val++) {
            if (tripleXor[val]) {
                count++;
            }
        }
        return count;
    }
};