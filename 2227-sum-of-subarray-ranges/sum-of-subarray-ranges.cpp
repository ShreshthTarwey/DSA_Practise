class Solution {
public:
    long long minSubArraySum(vector<int>& nums){
        stack<int>st1,st2;
        int n = nums.size();
        //Calculating prevSmaller
        vector<int>prevSmaller(n, -1);
        for(int i=0;i<n;i++){
            while(!st1.empty() && nums[st1.top()]>nums[i]){
                st1.pop();
            }
            if(!st1.empty()){
                prevSmaller[i] = st1.top();
            }
            st1.push(i);
        }
        //Calculating nextSmaller
        vector<int>nextSmaller(n, n);
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && nums[st2.top()]>=nums[i]){
                st2.pop();
            }
            if(!st2.empty()){
                nextSmaller[i] = st2.top();
            }
            st2.push(i);
        }

        //Calculating minSubarray sum
        long long sum = 0;
        for(int i=0;i<n;i++){
            int leftCount = i - prevSmaller[i];
            int rightCount = nextSmaller[i] - i;
            sum += (1ll * leftCount * rightCount * nums[i]);
        }
        return sum;
    }
    long long maxSubArraySum(vector<int>& nums){
        stack<int>st1, st2;
        int n = nums.size();
        //Finding prevGreater Element
        vector<int>prevGreater(n, -1);
        for(int i=0;i<n;i++){
            while(!st1.empty() && nums[st1.top()]<nums[i]){
                st1.pop();
            }
            if(!st1.empty()){
                prevGreater[i] = st1.top();
            }
            st1.push(i);
        }
        //Finding nextGreater Element
        vector<int>nextGreater(n, n);
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && nums[st2.top()]<=nums[i]){
                st2.pop();
            }
            if(!st2.empty()){
                nextGreater[i] = st2.top();
            }
            st2.push(i);
        }
        long long sum = 0;
        for(int i=0;i<n;i++){
            int leftCount = i - prevGreater[i];
            int rightCount = nextGreater[i] - i;
            sum += (1ll * leftCount * rightCount * nums[i]);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        //Finding sum of min subarrays-----
        long long minSum = minSubArraySum(nums);
        //Finding sum of max subarrays-------
        long long maxSum = maxSubArraySum(nums);
        return maxSum - minSum;
    }
};