class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &it: mp){
            if(it.second.size()>=3){
                int i=0;
                // int j=1;
                int k=2;
                while(k<it.second.size()){
                    ans = min(ans, it.second[k]-it.second[i]);
                    i++;
                    k++;
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return 2*ans;
    }
};