class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<long long>>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &it: mp){
            for(int j=1;j<it.second.size();j++){
                it.second[j] += it.second[j-1];
            }
        }
        unordered_map<int, int>mp2;
        vector<long long>ans;
        for(int i=0;i<n;i++){
            vector<long long>&arr = mp[nums[i]];
            if(arr.size()==1){
                ans.push_back(0);
                continue;
            }
            mp2[nums[i]]++;
            int index = mp2[nums[i]]-1;
            int size = arr.size();
            int n1 = index - 0;
            int n2 = size - index - 1;
            long long sum1 = 0;
            long long sum2 = 0;
            if(index-1>=0){
                sum1 = arr[index-1];
            }
            sum2 = arr[size-1] - arr[index];
            long long num = (1ll * (1ll * n1  * i) - sum1) + (1ll * sum2 - (1ll * n2 * i));
            ans.push_back(num);
        }
        return ans;
    }
};