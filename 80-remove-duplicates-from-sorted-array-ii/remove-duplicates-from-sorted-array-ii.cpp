class Solution {
public:
    void removeDup(vector<int>& nums, int index){
        if(index==nums.size()-1) return;
        while(index+1<nums.size() && nums[index]==nums[index+1]){
            nums.erase(nums.begin() + index+1);
        }
    }
    int removeDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                removeDup(nums, i+1);
            }
        }
        return nums.size();
    }
};