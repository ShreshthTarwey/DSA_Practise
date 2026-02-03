class Solution {
public:
    bool recFun(vector<int>& nums, int k, int partitionSum, vector<bool>& visited, int cSum, int idx){
        if(idx>nums.size()) return false;
        if(k==0) return true;
        if(cSum == partitionSum){
            return recFun(nums, k-1, partitionSum, visited, 0, 0);
        }

        for(int i=idx;i<nums.size();i++){
            if(nums[i] + cSum > partitionSum){
                break;
            }
            if(visited[i]) continue;
            visited[i] = true;
            if(recFun(nums, k, partitionSum, visited, cSum+nums[i], i+1)){
                return true;
            }
            visited[i] = false;
        }
        return false;

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum%k!=0) return false;
        int partitionSum = totalSum/k;
        vector<bool>visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        return recFun(nums, k, partitionSum, visited, 0, 0);
    }
};