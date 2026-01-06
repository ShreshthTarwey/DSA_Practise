class Solution {
public:
    bool recFun(vector<int>& nums, int index, long long prod, long long target){
        if(index>=nums.size() || prod>target) return false;
        if(prod == target) return true;
        bool pick = recFun(nums, index+1, prod*nums[index], target);
        bool notPick = recFun(nums, index+1, prod, target);

        return (pick || notPick);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        __int128 product = 1;
        for(auto it:nums){
            product*=it;
        }
        if(product!=(__int128)target*(__int128)target) return false;
        return recFun(nums, 0, 1, target);
    }
};