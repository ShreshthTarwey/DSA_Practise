class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto &it: nums){
            mp[it]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>>pq;
        for(auto &it: mp){
            pq.push({it.second, it.first});
        }
        vector<int>result;
        for(int i=0;i<k;i++){
            auto front = pq.top();
            pq.pop();
            result.push_back(front.second);
        }
        return result;
    }
};