class Solution {
public:
    bool solve(vector<int>& nums, long long target, __int128 product, int i, __int128 currP, bool found){
        if(i>=nums.size()){
            if (i >= nums.size()) {
            // Return true only if we actually found subset with product == target
            return found && (target == (product / target));
        }
        }
        if(currP==target){
            if(target==(product/target)){
                found = true;
                return true;

            }
            return false;
        }
        if(currP>target){
            return false;
        }

        bool take = solve(nums, target, product, i+1, currP*nums[i],found);
        bool notTake = solve(nums, target, product, i+1, currP,found);

        return (take||notTake);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        __int128 product = 1;
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
        }
        if (product > (__int128)target * target) return false;

        return solve(nums, target, product, 0,1,false);
    }
};