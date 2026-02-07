class Solution {
public:
    int recFun(string &s, int i, vector<int>& dp){
        if(i>=s.length()){
            return 1;
        }
        if(dp[i] !=-1 ) return dp[i];
        int single = 0;
        int dbl = 0;
        if(s[i]!='0')
            single = recFun(s, i+1, dp);
        if(i<s.length()-1){
            string num = "";
            num+=s[i];
            num+=s[i+1];
            if(num>="10" && num<="26"){
                dbl = recFun(s, i+2, dp);
            }
        }

        return dp[i] = (single + dbl);

    }
    int numDecodings(string s) {
        // vector<int>dp(s.length(), -1);
        // return recFun(s, 0, dp);
        //Tabulation ---------------------------------------------------------------------------
        vector<int>dp(s.length()+1, 0);
        dp[s.length()] = 1;
        for(int i=s.length()-1;i>=0;i--){
            int single = 0;
            int dbl = 0;
            if(s[i]!='0')
                single = dp[i+1];
            if(i<s.length()-1){
                string nums = "";
                nums+=s[i];
                nums+=s[i+1];
                if(nums>="10" && nums<="26"){
                    dbl = dp[i+2];
                }
            }
            dp[i] = (single + dbl);

        }
        return dp[0];
    }
};