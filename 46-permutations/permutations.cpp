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
    unordered_set<int>st;
    void solve_method2(vector<int>& nums, vector<int> &temp, vector<vector<int>>& ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        

        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
                temp.push_back(nums[i]);
                solve_method2(nums, temp, ans);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int i = 0;
        // solve(nums,i,ans);
        vector<int>temp;
        solve_method2(nums, temp, ans);
        return ans;
    }

};