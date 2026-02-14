class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int>mp;
        for(auto it: words){
            if(it.length()>=k){
                string str = it.substr(0, k);
                mp[str]++;
            }
        }
        int ans = 0;
        for(auto it: mp){
            if(it.second > 1){
                ans++;
            }
        }
        return ans;
    }
};