class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int>mp;
        for(auto &it: nums){
            mp[it]++;
        }
        int count = 0;
        int ans = 1;
        ans = max(ans, mp[1]%2==0 ? mp[1]-1 : mp[1]);
        mp.erase(1);
        for(auto &it: mp){
            int r = sqrt(it.first);
            if(it.second>=2){
                long long num = it.first;
                while(mp.find(num)!= mp.end() && mp[num]>1){
                    count+=2;
                    num = num*num;
                }
                ans = max(ans, count + (mp.contains(num) ? 1: -1));
            }
            count = 0;
        }
        return ans;
    }
};