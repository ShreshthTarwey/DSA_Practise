class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>&temp, int idx, vector<int>& nums){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for(int i=idx;i<nums.size();i++){

            if(st.count(nums[i])) continue;
            st.insert(nums[i]);
            swap(nums[i], nums[idx]);
            solve(ans, temp, idx+1,  nums);
            swap(nums[i], nums[idx]);
           
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int idx = 0;
        sort(nums.begin(), nums.end());
        solve(ans, temp, 0, nums);
        return ans;
    }
};