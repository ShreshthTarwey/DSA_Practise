class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        int resIndex = 0;
        vector<int>result(n, 0);
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                result[resIndex++] = nums[i];
            }
            else if(nums[i]>0){
                int count = nums[i];
                int index = (i+count)%n;
                result[resIndex++] = nums[index];
            }
            else{
                int count = abs(nums[i]);
                int index = i;
                while(count--){
                    index--;
                    if(index == -1){
                        index = n-1;
                    }
                }
                result[resIndex++] = nums[index];
            }
        }
        return result;
    }
};