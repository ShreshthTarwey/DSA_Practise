class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minE = *min_element(nums.begin(), nums.end());
        int maxE = *max_element(nums.begin(), nums.end());
        vector<int>ans;
        unordered_map<int, int>mp;
        for(auto a : nums){
            mp[a]++;
        }
        for(int i=minE;i<=maxE;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};