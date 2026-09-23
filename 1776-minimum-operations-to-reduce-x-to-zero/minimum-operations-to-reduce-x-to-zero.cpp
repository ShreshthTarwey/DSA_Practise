#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = 0;
        for (int v : nums) {
            total += v;
        }

        long long target = total - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();

        int left = 0;
        long long cur = 0;
        int max_len = -1;
        int n = nums.size();

        for (int right = 0; right < n; ++right) {
            cur += nums[right];

            while (cur > target && left <= right) {
                cur -= nums[left++];
            }

            if (cur == target) {
                max_len = max(max_len, right - left + 1);
            }
        }

        return max_len == -1 ? -1 : n - max_len;
    }
};