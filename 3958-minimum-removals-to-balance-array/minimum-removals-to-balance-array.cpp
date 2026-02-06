class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;
        sort(nums.begin(), nums.end());
        // int i = 0;
        int ans = INT_MAX;
        int j = 0;
        for(int i=0;i<n;i++){
            while((j<n && (long long)nums[j]<=((long long)nums[i]*(long long)k))){
                j++;
            }
            ans = min(ans, i +  (n-j));

        }

        return ans;

    }
};