class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==1) return nums;
        unordered_map<int, int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>>buckets(nums.size()+1);
        //each index of bucket stores elements with that frequency
        for(auto it: mp){
            buckets[it.second].push_back(it.first); 
        }
        vector<int>ans;
        for(int i=nums.size();i>=0;i--){
            if(k==0){
                return ans;
            }
            if(buckets[i].size()!=0){
                for(int j=0;j<buckets[i].size();j++){
                    ans.push_back(buckets[i][j]);
                    k--;
                    if(k==0){
                        break;
                    }
                }
            }
        }
        return ans;
    }
};