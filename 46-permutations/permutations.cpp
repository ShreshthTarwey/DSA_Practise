class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans){
        //Base Case
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }

        //1 Case solving from recursion

        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(nums, i+1, ans);
            //Backtracking
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int i = 0;
        solve(nums,i,ans);
        return ans;
    }

};