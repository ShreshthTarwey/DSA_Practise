class Solution {
public:
    void backtracking_method(vector<vector<int>>&res,vector<int>&temp,vector<int>&nums,int start_index,int k){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=start_index;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtracking_method(res,temp,nums,i+1,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>res;
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        backtracking_method(res,temp,nums,0,k);
        return res;
    }
};