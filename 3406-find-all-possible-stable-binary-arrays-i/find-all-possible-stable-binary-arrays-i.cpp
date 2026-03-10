class Solution {
public:
    int mainLimit;
    const int MOD = 1e9+7;
    int recFun(int last, int zero, int one, int limit, vector<vector<vector<vector<int>>>>& dp){
        //Base Case
        if(zero==0  && one==0){
            return 1;
        }
        int lastIndex = last;
        if(last!=-1 && dp[zero][one][lastIndex][limit]!=-1) return dp[zero][one][lastIndex][limit];
        int originalLimit = limit;
        bool canPickZero = true;
        bool canPickOne = true;
        if(limit==0){
            if(last==0){
                canPickZero = false;
            }
            else{
                canPickOne = false;
            }
            limit = mainLimit;
        }
        int opt1 = 0;
        int opt2 = 0;
        if(canPickZero && zero>0){
            int zeroLimit = limit;
            if(last == -1 || last== 0){
                zeroLimit = limit-1;
            }
            else{
                zeroLimit = mainLimit-1;
            }
            opt1 = recFun(0, zero-1, one, zeroLimit, dp);
        }
        if(canPickOne && one>0){
            int oneLimit = limit;
            if(last == -1 || last == 1){
                oneLimit = limit-1;
            }
            else{
                oneLimit = mainLimit-1;
            }
            // str+='1';
            opt2 = recFun(1, zero, one-1, oneLimit, dp);
            // str.pop_back();
        }
        int ans = (opt1+opt2)%MOD;
        if(last != -1)
            dp[zero][one][last][originalLimit] = ans;
        return ans;

    }
    int solve(int zero, int one, bool flag, int limit, vector<vector<vector<int>>>& dp){
        if(zero==0 && one==0){
            return 1;
        }
        if(dp[zero][one][flag]!=-1) return dp[zero][one][flag];
        long long result = 0;
        if(flag){
            for(int i=1;i<=min(zero, limit);i++){
                result += solve(zero-i, one, false, limit, dp)%MOD;
            }
        }
        else{
            for(int i=1;i<=min(one, limit);i++){
                result += solve(zero, one-i, true, limit, dp)%MOD;
            }
        }
        return dp[zero][one][flag] = result%MOD;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        // mainLimit = limit;
        // string str = "";
        // vector<vector<vector<vector<int>>>>dp(zero+1, vector<vector<vector<int>>>(one+1, vector<vector<int>>(2, vector<int>(limit+1, -1))));
        // return recFun(-1, zero, one, limit, dp);
        //---------------------------------------------Youtube Method---------------------------
        vector<vector<vector<int>>>dp(zero+1, vector<vector<int>>(one+1, vector<int>(2, -1)));
        int sumStartWithZero = solve(zero, one, false, limit, dp);
        int sumStartWithOne = solve(zero, one, true, limit, dp);
        return (sumStartWithZero + sumStartWithOne)%MOD;
    }
};