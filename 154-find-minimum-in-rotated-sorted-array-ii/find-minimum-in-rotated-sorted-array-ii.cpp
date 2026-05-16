class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int n = nums.size();
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mid-1>=0 && nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            if(mid+1<n && nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            while(l+1<n && l<=r && nums[l] == nums[l+1]){
                l++;
            }
            while(r-1>=0 && r>=l && nums[r] == nums[r-1]){
                r--;
            }
            if(nums[mid]<nums[r]){
                r = mid;
            }
            else if(nums[mid]>nums[r]){
                l = mid+1;
            }
            else{
                r--;
            }
        }
        return nums[0];
    }
};