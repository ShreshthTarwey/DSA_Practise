class Solution {
public:
    long long recFun(vector<int>& robot, vector<int>& fac, int i, int j, vector<vector<long long>>& dp){
        if(i>=robot.size()){
            return 0;
        }
        if(j>=fac.size()){
            return 1e18;
        }
        if(dp[i][j] != -1) return dp[i][j];
        long long take = abs(robot[i] - fac[j]) + recFun(robot, fac, i+1, j+1, dp);
        long long skip = recFun(robot, fac, i, j+1, dp);
        return dp[i][j] = min(take, skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        // sort(factory.begin(), factory.end());
        vector<int>fac;
        for(auto &it: factory){
            for(int i=0;i<it[1];i++){
                fac.push_back(it[0]);
            }
        }
        sort(fac.begin(), fac.end());
        // vector<vector<long long>>dp(robot.size(), vector<long long>(fac.size(), -1));
        // return recFun(robot, fac, 0, 0, dp);
        //Tabulation method-------------------------------------------------------------------
        vector<vector<long long>>dp(robot.size()+1, vector<long long>(fac.size()+1, 0));
        for(int i=0;i<robot.size();i++){
            dp[i][fac.size()] = 1e18;
        }
        for(int i=robot.size()-1;i>=0;i--){
            for(int j=fac.size()-1;j>=0;j--){
                long long take = abs(robot[i] - fac[j]) + dp[i+1][j+1];
                long long skip = dp[i][j+1];
                dp[i][j] = min(take, skip);
            }
        }
        return dp[0][0];
    }
};