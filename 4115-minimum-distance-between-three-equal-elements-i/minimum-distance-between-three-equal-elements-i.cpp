class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &it: mp){
            if(it.second.size()>=3){
                int i=0;
                int j=1;
                int k=2;
                while(k<it.second.size()){
                    int dis = abs(it.second[i] - it.second[j]) + abs(it.second[j] - it.second[k]) + abs(it.second[k] - it.second[i]);
                    ans = min(ans, dis);
                    i++;
                    j++;
                    k++;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};