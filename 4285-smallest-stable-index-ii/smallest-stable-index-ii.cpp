class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxTill(n);
        vector<int>minTill(n);
        int maxNum = nums[0];
        for(int i=0;i<n;i++){
            maxNum = max(maxNum, nums[i]);
            maxTill[i] = maxNum;
        }
        //Filling minTIll
        int minNum = nums[n-1];
        for(int j=n-1;j>=0;j--){
            minNum = min(minNum, nums[j]);
            minTill[j
            ] = minNum;
        }
        for(int i=0;i<n;i++){
            if(maxTill[i] - minTill[i] <= k){
                return i;
            }
        }
        return -1;
    }
};