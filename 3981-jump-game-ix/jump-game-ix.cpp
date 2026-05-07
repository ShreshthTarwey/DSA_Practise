class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftMax(n, 0);
        vector<int>rightMin(n, 0);
        vector<int>ans(n, 0);
        int maxNum = INT_MIN;
        for(int i=0;i<n;i++){
            maxNum = max(maxNum, nums[i]);
            leftMax[i] = maxNum;
        }
        ans[n-1] = leftMax[n-1];
        int minNum = nums[n-1];
        for(int i=n-1;i>=0;i--){
            rightMin[i] = minNum;
            minNum = min(minNum, nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            if(leftMax[i]>rightMin[i]){
                ans[i] = ans[i+1];
            }
            else{
                ans[i] = leftMax[i];
            }
        }
        return ans;
    }
};