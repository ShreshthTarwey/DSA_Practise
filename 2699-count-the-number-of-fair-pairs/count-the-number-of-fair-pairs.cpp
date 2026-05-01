class Solution {
public:
    long long bruteForce(vector<int>& nums, int lower, int upper){
         long long count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){ //T.C-> O(n^2)
            for(int j=i+1;j<n;j++){
                if(nums[i] + nums[j] >= lower && nums[i] + nums[j] <= upper){
                    count++;
                }
            }
        }
        return count;
    }
    long long lessThanBound(vector<int>&nums, int upper){
        int i = 0;
        int j = nums.size()-1;
        // 0 1 4 4 5 7
        long long count = 0;  
        while(i<j){
            if(nums[i] + nums[j] > upper){
                j--;
                continue;
            }
            else{
                count+= j - i;
                i++;
                // j--;
            }
        }
        return count;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
    //    return bruteForce(nums, lower, upper);
        // a + b >= lower
        // a + b - lower >= 0
        // a + b <= upper
        // a + b - upper <= 0
        // a - lower + b = a + b - lower
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long n1 = lessThanBound(nums, upper);
        long long n2 = lessThanBound(nums, lower-1);
        return n1 - n2;
    }
};