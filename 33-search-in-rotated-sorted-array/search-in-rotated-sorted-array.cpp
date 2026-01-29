class Solution {
public:
    int find_pivot(vector<int>&arr){
        int s=0;
        int e=arr.size()-1;
        int n = arr.size();
        
        while(s<=e){
            if(s==e){
                return s;
            }
            int mid = s+(e-s)/2;
            
            if(mid!=n-1&&arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[s]>arr[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }
    int binary_search(vector<int>&arr,int s,int e,int target){
        int mid = s+(e-s)/2;
        while(s<=e){
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }
    int findPivot2(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            // if(start==end){
            //     return start;
            // }
            int mid = start + ((end-start)>>1);
            if(mid>0 && nums[mid-1]>nums[mid]){
                return mid;
            }
            else if(mid<nums.size()-1 && nums[mid]>nums[mid+1]){
                return mid+1;
            }
            else if(nums[mid]<nums[start]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return 0;
    }
    int binarySearch(vector<int>&nums, int target, int start, int end){
        while(start<=end){
            int mid = start + ((end-start)>>1);
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
        // int pivot = find_pivot(nums);
        // int n = nums.size();
        // if(pivot==-1) return -1;
        // if(target>=nums[0]&&target<=nums[pivot]){
        //     //line A
        //     return binary_search(nums,0,pivot,target);
        // }
        // else if(pivot+1<n&&target>=nums[pivot+1] && target<=nums[n-1]){
        //     return binary_search(nums,pivot+1,n-1,target);
        // }
        // return -1;
        //Revision doing again-------------------------------------------------------------------------









        int pivot = findPivot2(nums, target);
        if(pivot == -1) return -1;
        if(pivot>0 && target>=nums[0] && target<=nums[pivot-1]){
            return binarySearch(nums, target, 0, pivot-1);
        }
        else{
            return binarySearch(nums, target, pivot, nums.size()-1);
        }
    }
};