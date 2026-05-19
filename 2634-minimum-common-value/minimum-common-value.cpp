class Solution {
public:
    int twoPointer(vector<int>& nums1, vector<int>& nums2){
        int i = 0;
        int j=0;
        int n = nums1.size();
        int m = nums2.size();
        while(i<n && j<m){
            if(nums1[i] == nums2[j]){
                return nums1[i];
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return -1;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        //two pointer approach
        return twoPointer(nums1, nums2);
    }
};