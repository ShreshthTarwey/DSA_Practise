class Solution {
public:
    bool recFun(string &s, unordered_map<string, int>& mp, int i, int j, vector<vector<int>>& dp){
        if(i==j && i>=s.length()){
            return true;
        }
        if(j>=s.length() || i>=s.length()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        string str = s.substr(i, j-i+1);
        bool opt1 = false;
        bool opt2 = false;
        if(mp.find(str)!=mp.end()){
            opt1 = recFun(s, mp, j+1, j+1, dp);
        }
        opt2 = recFun(s, mp, i, j+1, dp);

        return dp[i][j] = (opt1 || opt2);

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int>mp;
        for(auto it : wordDict){
            mp[it]++;
        }
        vector<vector<int>>dp(s.length(), vector<int>(s.length(), -1));
        return recFun(s, mp, 0,0, dp);
    }
};