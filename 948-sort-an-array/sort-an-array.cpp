class Solution {
public:
    int partition(vector<int>&arr,int start,int end)
    {
        int pos = start;
        for(int i=start;i<=end;i++)
        {
            if(arr[i]<=arr[end]){
                swap(arr[i],arr[pos++]);
            }
        }
        return pos-1;
    }
    void quickSort(vector<int>&arr,int start,int end)
    {
        if(start>=end){
            return;
        }

        int pivot = partition(arr,start,end);
        quickSort(arr,start,pivot-1);
        quickSort(arr,pivot+1,end);
    }
    void priorityQueueMethod(vector<int>&  nums){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it: nums){
            pq.push(it);
        }
        int index = 0;
        while(!pq.empty()){
            nums[index++] = pq.top();
            pq.pop();
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // quickSort(nums,0,nums.size()-1); // TLE is coming in this method
        priorityQueueMethod(nums);
        return nums;
    }
};