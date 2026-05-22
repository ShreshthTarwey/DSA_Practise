class Solution {
public:
    int findPivot(vector<int>& nums, int l, int r){
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mid-1>=0 && nums[mid-1] > nums[mid]){
                return mid;
            }
            else if(nums[mid]<nums[r]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return 0;
    }
    int binarySearch(vector<int>& nums, int l, int r, int target){
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums, 0, nums.size()-1);
        if(target>=nums[pivot] && target<=nums[nums.size()-1]){
            return binarySearch(nums, pivot, nums.size()-1, target);
        }
        else{
            return binarySearch(nums, 0, pivot-1, target);
        }
    }
};