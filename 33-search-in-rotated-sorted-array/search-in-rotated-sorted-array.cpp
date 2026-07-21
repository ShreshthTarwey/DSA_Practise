class Solution {
public:
    int binarySearch1(vector<int>& nums){
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(mid-1>=0 && nums[mid-1]>nums[mid]){
                return mid;
            }
            else if(nums[mid]<nums[r]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
    int binarySearch2(vector<int>& nums, int start, int end, int target){
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = binarySearch1(nums);
        if(pivot == -1){
    return binarySearch2(nums,0,nums.size()-1,target);
}
        int opt1 = binarySearch2(nums, pivot, nums.size()-1, target);
        int opt2 = binarySearch2(nums, 0, pivot-1, target);
        return opt1 == -1 ? opt2: opt1;
    }
};