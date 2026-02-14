class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>matrix(100, vector<double>(100, 0.0));
        // double champ = poured;
        matrix[0][0] = poured;
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                if(matrix[i][j]>1.0){
                    double champ = matrix[i][j] - 1.0;
                    matrix[i][j] = 1.0;
                    if(i+1<100 && j+1<100){
                        double left = champ/2.0;
                        matrix[i+1][j] += left;
                        matrix[i+1][j+1] += left;
                    }
                    
                }
                
            }
        }
        return matrix[query_row][query_glass];
    }
};