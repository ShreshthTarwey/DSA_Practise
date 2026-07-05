class Solution {
public:
    const int MOD = 1e9+7;
    int recFun(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0){
            return 0;
        }
        if(i<0 || j<0 || j>=matrix.size() || i>=matrix.size() || matrix[i][j] == 'X'){
            return INT_MIN;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans;
        if(matrix[i][j] == 'S'){
            ans = 0;
        }
        else{
            ans = matrix[i][j] - '0';
        }
        int option1 = recFun(matrix, i-1, j, dp);
        int option2 = recFun(matrix, i, j-1, dp);
        int option3 = recFun(matrix, i-1, j-1, dp);

        ans += max({option1, option2, option3});
        return dp[i][j] = ans;
    }
    int recFun2(vector<vector<char>>& matrix, int i, int j, int target, vector<vector<vector<int>>>& dp2){
        if(i<0 || j<0 || j>=matrix.size() || i>=matrix.size() || matrix[i][j] == 'X'){
            return 0;
        }
        if(i==0 && j==0 && target == 0){
            return 1;
        }
        if(dp2[i][j][target] != -1){
            return dp2[i][j][target];
        }
        int num = 0;
        if(matrix[i][j] != 'S' && matrix[i][j] != 'E'){
            num = matrix[i][j] - '0';
        }
        int option1 = recFun2(matrix, i-1, j, target-num, dp2);
        int option2 = recFun2(matrix, i, j-1, target-num, dp2);
        int option3 = recFun2(matrix, i-1, j-1, target-num, dp2);
        return dp2[i][j][target] = (option1 + option2 + option3)%MOD;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board[0].length();
        vector<vector<char>>matrix(n, vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = board[i][j];
            }
        }
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int target = recFun(matrix, n-1, n-1, dp);
        // cout<<target;
        // return {0, 0};
        //Find number of paths having sum = target
        if(target<0){
            return {0, 0};
        }
        vector<vector<vector<int>>>dp2(n, vector<vector<int>>(n, vector<int>(target+1, -1)));
        int num = recFun2(matrix, n-1, n-1, target, dp2);
        return {target, num};
    }
};