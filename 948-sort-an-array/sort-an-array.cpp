class Solution {
public:
    int partition(vector<int>& arr, int start, int end) {
        int pos = start;
        for (int i = start; i <= end; i++) {
            if (arr[i] <= arr[end]) {
                swap(arr[i], arr[pos++]);
            }
        }
        return pos - 1;
    }
    void quickSort(vector<int>& arr, int start, int end) {
        if (start >= end) {
            return;
        }

        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
    void priorityQueueMethod(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : nums) {
            pq.push(it);
        }
        int index = 0;
        while (!pq.empty()) {
            nums[index++] = pq.top();
            pq.pop();
        }
    }

    void putElementOf2ndArrayInCorrectPosition(vector<int>& nums, int start,
                                               int end, int index) {
        int key = nums[index];
        // Keep shifting elements until right element is found
        int i = index + 1;
        while (i <= end && nums[i] < key) {
            nums[i - 1] = nums[i];
            i++;
        }
        nums[i - 1] = key;
    }

    void mergeWithoutExtraSpace1(vector<int>& nums, int left, int mid,
                                 int right) {
        // int s = left;
        // int e = right;
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
                putElementOf2ndArrayInCorrectPosition(nums, mid + 1, right, j);
            }
            i++;
        }
    }
    void mergeWithoutExtraSpace2(vector<int>& nums, int start, int mid,
                                 int end) {
        int totalLength = (end - start + 1);
        int gap = totalLength / 2 + (totalLength % 2);
        
        while (gap > 0) {
            int i = start;
        int j = start+gap;
            while (j <= end) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
                i++;
                j++;
            }
            gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
        }
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        // mergeWithoutExtraSpace1(nums,left,mid,right); //Here is the main
        // thing
        mergeWithoutExtraSpace2(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        // quickSort(nums,0,nums.size()-1); // TLE is coming in this method
        // priorityQueueMethod(nums); //This is working but taking extra space
        // complexity

        // Now we are going to so this with help of in place merge sort

        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};