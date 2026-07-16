class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefixGrid(n);
        
        long long maxi = LLONG_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi, 1ll * nums[i]);
            prefixGrid[i] = gcd(maxi, nums[i]);
        }
        sort(prefixGrid.begin(), prefixGrid.end());
        long long sum = 0;
        int i=0;
        int j = n-1;
        while(i<j){
            sum += gcd(prefixGrid[i] , prefixGrid[j]);
            i++;
            j--;
        }
        return sum;
    }
};