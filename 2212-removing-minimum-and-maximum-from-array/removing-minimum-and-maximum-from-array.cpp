class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        int minElementIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxElementIndex = max_element(nums.begin(), nums.end()) - nums.begin();
        //case I--> Deleting both elements from front
        ans = min(ans, max(minElementIndex, maxElementIndex) + 1);
        //Case II---> Deleting both from back
        ans = min(ans, n - min(minElementIndex, maxElementIndex));
        //Case III--> Deleting from both ends
        ans = min(ans, 1 + min(minElementIndex, maxElementIndex) + (n - max(minElementIndex, maxElementIndex)));

        return ans;
    }
};