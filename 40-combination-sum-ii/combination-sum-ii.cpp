class Solution {
public:
    void combination_helper(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target, int start_index){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;

        for(int i=start_index;i<candidates.size();i++){
            if(i > start_index && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            combination_helper(candidates, temp, ans, target - candidates[i], i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(), candidates.end());
        combination_helper(candidates,temp,ans,target,0);
        return ans;

    }
};