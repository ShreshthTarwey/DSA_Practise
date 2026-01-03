class Solution {
public:
    bool isSafe(vector<vector<char>>& grid, int i, int j, char &color){
        //Check top part
        if(i>0 && grid[i-1][j] == color) return false;
        //check left part
        if(j>0 && grid[i][j-1] == color) return false;
        return true;
    }
    long long recFun(vector<vector<char>>& grid, int i, int j){
        if(i==grid.size()) return 1;

        int next_i = i;
        int next_j = j+1;
        if(next_j==3){
            next_i = i+1;
            next_j = 0;
        }
        vector<char>colors = {'R', 'Y','G'};
        long long count = 0;
        for(auto it: colors){
            if(isSafe(grid, i,j,it)){
                grid[i][j] = it;
                long long MOD = 1e9 + 7;
                count = (count + recFun(grid, next_i, next_j))%MOD;

                //Bactktrack
                grid[i][j] = '.';
            }
        }
        return count;
    }
    int bruteForceMyMethod(int n){
        vector<vector<char>>grid(n, vector<char>(3, '.'));
        return recFun(grid, 0, 0);
    }
    vector<string>states = {
        "RGY", "RGR", "RYG", "RYR", "YGR", "YRG", "YRY", "YGY", "GRY", "GYR", "GRG", "GYG"
    };
    int M = 1e9+7;
    int recursiveFun(int n, int index, vector<vector<int>>& dp){
        //Base Case
        if(n==0) return 1;
        if(dp[n][index]!=-1) return dp[n][index];
        string last = states[index];
        long long result = 0;
        for(int i=0;i<12;i++){
            string curr = states[i];
            if(curr == last) continue;
            bool conflict = false;
            for(int col = 0;col<3;col++){
                if(curr[col]==last[col]){
                    conflict = true;
                    break;
                }
            }

            if(!conflict){
                long long val = recursiveFun(n - 1, i, dp);
                result = (result + val) % M; // Keep result small!
            }
        }
        return dp[n][index] = result;

    }
    int optimizedDpMethod(int n){
        long long result = 0;
        vector<vector<int>>dp(n, vector<int>(12, -1));
        for(int i=0;i<12;i++){
            long long val = recursiveFun(n - 1, i, dp);
            result = (result + val) % M; // Keep result small!
        }
        return result % M;
    }
    int mostOptimizedWay(int n, vector<int>& dp){
        if(n<=0) return 0;
        if(dp[n] != -1) return dp[n];
        if(n==1) return 12;
        if(n==2) return 54;

        long long term1 = (5LL * mostOptimizedWay(n-1, dp)) % M;
        long long term2 = (2LL * mostOptimizedWay(n-2, dp)) % M;

        return dp[n] = (term1 - term2 + M) % M;

    }
    int numOfWays(int n) {
        // return bruteForceMyMethod(n);
        // return optimizedDpMethod(n); //Very good approach
        vector<int>dp(5001, -1);
        return mostOptimizedWay(n, dp); //Using observed recurence relation f(n) = 5(f(n-1)) - 2(f(n-2))
    }
};