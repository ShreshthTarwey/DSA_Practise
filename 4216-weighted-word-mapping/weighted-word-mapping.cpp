class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int, char>mp;
        int index = 0;
        for(int i=25;i>=0;i--){
            mp[index++] = 'a' + i;
        }
        string ans = "";
        for(auto it: words){
            int sum = 0;
            for(auto jt: it){
                sum += weights[jt - 'a'];
            }
            sum = sum%26;
            ans += mp[sum];
        }
        return ans;
    }
};