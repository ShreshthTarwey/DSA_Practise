class Solution {
public:
    const int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>arr(n*m);
        int index = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[index++] = grid[i][j]%MOD;
            }
        }
        vector<int>leftPrefix(n*m, 1);
        int prod = 1;
        for(int i=1;i<n*m;i++){
            leftPrefix[i] = (leftPrefix[i-1] * arr[i-1])%MOD; 
        }

        long long r = 1;
        for(int i=(n*m)-1;i>=0;i--){
            leftPrefix[i] = (leftPrefix[i] * r)%MOD;
            r = (r*arr[i])%MOD;
        }
        index = 0;
        vector<vector<int>>ans(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = leftPrefix[index++];
            }
        }
        return ans;

    }
};