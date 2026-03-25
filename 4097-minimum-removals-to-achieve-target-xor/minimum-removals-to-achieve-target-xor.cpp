class Solution {
public:
    void generate(int idx, int end, vector<int>&nums, int currXor, int size, unordered_map<int, int>&mp){
        if(idx == end){
            mp[currXor] = max(mp[currXor], size);
            return;
        }
        generate(idx+1, end, nums, currXor, size, mp);
        generate(idx+1, end, nums, currXor ^ nums[idx], size+1, mp);
    }
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>leftMp;
        generate(0, n/2, nums, 0, 0, leftMp);
        unordered_map<int, int>rightMp;
        generate(n/2, n, nums, 0, 0, rightMp);
        int maxKept = INT_MIN;
        for(auto &it : leftMp){
            int needed = it.first^target;
            if(rightMp.find(needed)!=rightMp.end()){
                int size = it.second + rightMp[needed];
                maxKept = max(maxKept, size);
            }
        }
        if(maxKept == INT_MIN) return -1;
        return n - maxKept;
    }
};