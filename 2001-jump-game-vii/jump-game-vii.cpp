class Solution {
public:
    bool recFun(string &s, int idx, int minJump, int maxJump, vector<int>& dp){
        int n = s.length();
        if(idx>=n){
            return false;
        }
        if(idx == n-1){
            return true;
        }
        if(dp[idx] != -1) return dp[idx];
        for(int jump = idx+minJump; jump<=idx+maxJump; jump++){
            if(jump>=n){
                break;
            }
            if(s[jump] == '0'){
                if(recFun(s, jump, minJump, maxJump, dp)){
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        // // vector<int>dp(s.length(), -1);
        // // return recFun(s, 0, minJump, maxJump, dp); //TLE
        // //----Tabulization
        // int n = s.length();
        // vector<bool>dp(s.length()+1, false);
        // for(int i=n;i>=0;i--){
        //     if(i==n-1){
        //         dp[i] = true;
        //         continue;
        //     }
        //     for(int jump = i + minJump;jump<=i+maxJump; jump++){
        //         if(jump>=n){
        //             break;
        //         }
        //         if(s[jump] == '0' && dp[jump]){
        //             dp[i] = true;
        //             break;
        //         }
        //     }
        // }
        // return dp[0];//TLE  is coming
        //Optimized Way
        int n = s.length();
        vector<int>t(n, 0);
        t[0] = 1;
        int count = 0;
        for(int j=1;j<=n-1;j++){
            if(j-minJump>=0){
                count += t[j-minJump];
            }
            if(j-maxJump-1>=0){
                count -= t[j-maxJump-1];
            }
            if(count>0 && s[j] == '0'){
                t[j] = 1;
            }
        }
        return t[n-1];
    }
};