class Solution {
public:
    void solve(vector<int>&nums, int idx, int &count){
        if(idx>=nums.size()){
            count++;
            return;
        }
        for(int i=idx;i<nums.size();i++){
            int pos = idx+1;
            int val = nums[i];
            if((pos%val==0) || (val%pos==0)){
                swap(nums[i], nums[idx]);
                solve(nums, idx+1, count);
                swap(nums[i], nums[idx]);
            }
        }
    }
    int countArrangement(int n) {
        int count = 0;
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        solve(nums, 0, count);
        return count;
    }
};