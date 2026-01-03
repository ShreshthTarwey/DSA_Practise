class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int>>st;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i] - nums[j])==k){
                    if(st.find({nums[i], nums[j]})==st.end() && st.find({nums[j], nums[i]})==st.end()){
                        st.insert({nums[i], nums[j]});
                    }
                }
            }
        }
        return st.size();
    }
};