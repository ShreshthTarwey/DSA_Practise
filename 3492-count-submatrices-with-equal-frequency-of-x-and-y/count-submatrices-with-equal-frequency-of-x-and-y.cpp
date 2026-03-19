class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        // return 0;
        int n = grid.size();
        int m = grid[0].size();
        // vector<bool>flag(m, false);
        // vector<bool>flag2(n, false);
        vector<vector<int>>mat(n, vector<int>(m, 0));
        vector<vector<int>>countX(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    mat[i][j] = 1;
                    countX[i][j] = 1;
                }
                else if(grid[i][j] == 'Y'){
                    mat[i][j] = -1;
                }
            }
        }
        //Prefix1
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j] += mat[i][j-1];
                countX[i][j] += countX[i][j-1];
            }
        }
        //Prefix2
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                mat[i][j] += mat[i-1][j];
                countX[i][j] += countX[i-1][j];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(countX[i][j]>0 && mat[i][j] == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};