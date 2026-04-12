class Solution {
public:
    pair<int, int> getPoints(char &c){
        int dis = c - 'A';
        int row = dis/6;
        int col = dis%6;
        return {row, col};
    }
    int method1(string &word, int idx, int x1, int y1, int x2, int y2, vector<vector<vector<vector<vector<int>>>>>& dp){
        if(idx>=word.length()){
            return 0;
        }
        if(dp[idx][x1 + 1][y1 + 1][x2 + 1][y2 + 1] != -1) return dp[idx][x1 + 1][y1 + 1][x2 + 1][y2 + 1];
        auto [x, y] = getPoints(word[idx]);
        if(x1==-1 && y1==-1 && x2==-1 && y2==-1){
            return method1(word, idx+1, x, y, x2, y2, dp);
        }
        int result = INT_MAX;
        if(x2 == -1 && y2 == -1){
            result = min(result, method1(word, idx+1, x1, y1, x, y, dp));
        }
        result = min(result, abs(x1 - x) + abs(y1 - y) + method1(word, idx+1, x, y, x2, y2, dp));
        result = min(result, abs(x2 - x) + abs(y2 - y) + method1(word, idx+1, x1, y1, x, y, dp));
        return dp[idx][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = result;
    }
    int minimumDistance(string word) {
        vector<vector<vector<vector<vector<int>>>>>dp(word.length(), vector<vector<vector<vector<int>>>>(7, vector<vector<vector<int>>>(7, vector<vector<int>>(7, vector<int>(7, -1)))));
        return method1(word, 0, -1, -1, -1, -1, dp); //Using 5d Dp
    }
};