class Solution {
public:
    int minOperations(vector<int>& nums) {
        //checking if possible to  sort
        int n = nums.size();
        //increasing cyclic shift
        bool flag1 = true;
        bool flag2 = true;
        for(int i=0;i<n;i++){
            if((nums[i] + 1)%n != (nums[(i+1)%n])%n){
                flag1 = false;
                break;
            }
        }
        //decreaging cyclic shift
        for(int i=0;i<n;i++){
            if((nums[i] + 1)%n != (nums[(i-1 + n)%n])%n){
                flag2 = false;
                break;
            }
        }
        if(!flag2 && !flag1){
            return -1;
        }
        else{
            auto it = min_element(nums.begin(), nums.end());
            int idx = distance(nums.begin(), it);
            if(flag1){
                return min(idx, 2 + (n-idx)%n);
            }
            else{
                return min(n-idx, idx+2);
            }
        }
    }
};