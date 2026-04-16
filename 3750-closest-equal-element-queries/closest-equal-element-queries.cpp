class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>>mp;
        vector<int>ans;
        int totalN = nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<queries.size();i++){
            int res = INT_MAX;
            int idx = queries[i];
            auto &arr = mp[nums[idx]];
            int n = arr.size();
            if(n<=1){
                ans.push_back(-1);
                continue;
            }
            int targetIndex = lower_bound(arr.begin(), arr.end(), idx) - arr.begin();
            int nextRight = arr[(targetIndex + 1)%n];
            int nextLeft = arr[(targetIndex - 1 + n)%n];
            res = min({res, abs(idx - nextRight), totalN - abs(idx - nextRight)});
            res = min({res, abs(idx - nextLeft), totalN - abs(idx - nextLeft)});
            ans.push_back(res);
        }
        return ans;
    }
};