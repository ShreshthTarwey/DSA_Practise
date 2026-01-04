class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j=1;
        set<pair<int,int>>st;
        // int count = 0;
        while(j<nums.size() && i<nums.size() && j>=i){
            if(i==j) j++;
            if(j>=nums.size()) break;
            int sum = abs(nums[j]-nums[i]); 

            if( sum == k){
                // count++;
                if(st.find({nums[i], nums[j]})==st.end() && st.find({nums[j], nums[i]})== st.end()){
                    st.insert({nums[i], nums[j]});
                }
                i++;
                j++;
                continue;
            }
            if(sum>k) i++;
            else j++;
        } 
        return st.size();
    }
};