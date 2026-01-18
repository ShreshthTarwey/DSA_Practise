class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>rowCumm(n, vector<int>(m,0));
        vector<vector<int>>colCumm(n, vector<int>(m,0));
        //Finding row Cumm sum
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rowCumm[i][j] += (j==0)? grid[i][j] : grid[i][j] + rowCumm[i][j-1];
            }
        }
        //Finding colCumm
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // rowCumm[i][j] += (j==0)? grid[i][j] : grid[i][j] + rowCumm[i][j-1];
                colCumm[i][j] += (i==0)? grid[i][j] : grid[i][j] + colCumm[i-1][j];
            }
        }

        int Sides = min(n,m);
        //Looping from greater side to smaller
        for(int side = Sides;side>=1;side--){
            for(int i = 0;i+side<=n;i++){
                for(int j=0;j+side<=m;j++){
                    bool isOk = true;
                    //Checking row
                    int target = rowCumm[i][j+side-1] - ((j==0) ? 0 : rowCumm[i][j-1]);
                    int sum=0;
                    for(int rowP = i+1;rowP<i+side;rowP++){
                        sum = rowCumm[rowP][j+side-1] - ((j==0) ? 0 : rowCumm[rowP][j-1]);
                        if(sum!=target){
                            isOk = false;
                            break;
                        }
                    }
                    //Checking col
                    if(!isOk) continue;
                    int target2 = colCumm[i+side-1][j] - ((i==0) ? 0 : colCumm[i-1][j]);
                    int sum2 = 0;
                    for(int colP=j+1;colP<j+side;colP++){
                        sum2 = colCumm[i+side-1][colP] - ((i==0) ? 0 : colCumm[i-1][colP]);
                        if(sum2!=target2){
                            isOk = false;
                            break;
                        }
                    }
                    if(!isOk) continue;
                    //Checking diagonal and antidiagonal
                    int dig = 0;
                    int antiDig = 0;
                    for(int k=0;k<side;k++){
                        dig += grid[i+k][j+k];
                        antiDig += grid[i+k][j+side-k-1];
                    }
                    if(dig==target && antiDig==target){
                        return side;
                    }
                }
            }
        }
        return 1;
    }
};