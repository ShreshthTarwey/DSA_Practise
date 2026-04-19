class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end, int target){
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid]>=target){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
    int binarySearchMethod(vector<int>&nums1, vector<int>&nums2){
                int ans = INT_MIN;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0;i<n;i++){
            // ans = max(ans, abs(i - binarySearch(nums2, i, m, nums1[i])));
            int j = binarySearch(nums2, i, m-1, nums1[i]);
            if(j != -1){
                ans = max(ans, abs(i-j));
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
    int twoPointer(vector<int>& nums1, vector<int>& nums2){
        int i=0;
        int j=0;
        int ans = INT_MIN;
        while(i<nums1.size() && j<nums2.size()){
            if(i > j){
                j=i;
            }
            if(nums1[i]>nums2[j]){
                i++;
            }
            else{
                ans = max(ans, abs(j-i));
                j++;
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // return binarySearchMethod(nums1, nums2); //T.C-> nlogn
        return twoPointer(nums1, nums2);
    }
};