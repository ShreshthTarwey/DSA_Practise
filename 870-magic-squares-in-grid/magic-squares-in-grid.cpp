class Solution {
public:
    bool isDistinct(vector<vector<int>>& grid, int r, int c){
        vector<bool>seen(10, false);
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                int val = grid[i][j];
                if(seen[val] == true) return false;
                if(val<1 || val>9) return false;
                seen[val] = true;
            }
        }
        return true;
    }
    int myMethod(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(i>=n || i+1>=n || i+2>=n){
                break;
            }
            for(int j=0;j<m;j++){
                if(j>=m || j+1 >= m || j+2 >=m){
                    break;
                }

                if(!isDistinct(grid, i, j)) continue;

                int row1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                int row2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
                if(row1 != row2) continue;
                int row3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                if(row2 != row3) continue;


                int dig1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int dig2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
                if(row3 != dig1 || row3!= dig2) continue;


                int col1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
                int col2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
                int col3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
                if(row3!= col1 || row3 != col2 || row3 != col3) continue;

                count++;
            }
        }
        return count;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        return myMethod(grid);
    }
};