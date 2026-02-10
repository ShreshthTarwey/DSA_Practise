class Solution {
public:
    bool isPalindrome(string &s){
        int i=0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    void recFun(string &s, int idx, vector<vector<string>>& ans, vector<string>& temp, vector<vector<int>>& dp){
        if(idx>=s.length()){
            if(!temp.empty()){
                ans.push_back(temp);
                // temp.clear();
            }
            return;
        }

        string tempStr = "";
        for(int i=idx;i<s.length();i++){
            tempStr+=s[i];
            if(dp[idx][i]){
                temp.push_back(tempStr);
                recFun(s, i+1, ans, temp, dp);
                temp.pop_back();
            }
        }

    }
    bool preCompute(string &s, vector<vector<int>>& dp, int i, int j){
        if(i<0 || i>=s.length() || j<0 || j>=s.length()){
            return false;
        }
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = (s[i] == s[j]) && preCompute(s, dp, i+1, j-1);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<int>>dpPalin(s.length(), vector<int>(s.length(), -1));
        int n = s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                preCompute(s, dpPalin, i, j);
            }
        }
        // preCompute(s, dpPalin, 0, s.length()-1);
        vector<string>temp;
        vector<vector<string>>ans;
        recFun(s, 0, ans, temp, dpPalin);
        return ans;
    }
};