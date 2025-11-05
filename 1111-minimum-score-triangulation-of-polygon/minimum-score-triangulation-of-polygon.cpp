class Solution {
public:

    // int dp[51][51];

    int solve(vector<int>& values, int i, int j, vector<vector<int>>&dp){
        //Base Case
        if(j-i+1<3){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int result = INT_MAX;
        for(int k=i+1;k<j;k++){
            int wt = values[i] * values[k] * values[j]
                    +solve(values, i,k,dp)
                    + solve(values, k,j,dp);

            result = min(result, wt);
        }
        return dp[i][j] = result;
    }
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>dp(51,vector<int>(51,-1));
        return solve(values, 0, values.size()-1, dp);
        
    }
};