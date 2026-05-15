class Solution {
public:
    int findPivot(vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;
        int index = -1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(mid>0 && nums[mid-1]>nums[mid]){
                return mid;
            }
            else if(mid<nums.size()-1 && nums[mid]>nums[mid+1]){
                return mid+1;
            }
            else if(nums[mid]<nums[left]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return 0;
    }
    int findMin(vector<int>& nums) {
        int pivot = findPivot(nums);
        return nums[pivot];
    }
};