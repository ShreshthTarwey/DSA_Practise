class Solution {
public:
    int findSum(int i, int j, int row, int col, vector<vector<int>>& grid){
        return grid[row][col] - (i>0 ? grid[i-1][col] : 0) - (j>0 ? grid[row][j-1] : 0) + ((i>0 && j>0) ? grid[i-1][j-1] : 0); 
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        //Building prefix Sum 2D array
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefixSum[i][j] = (i>0 ? prefixSum[i-1][j] : 0) +
                                    (j>0 ? prefixSum[i][j-1] : 0) -
                                    ((i>0 && j>0) ? prefixSum[i-1][j-1] : 0) + mat[i][j];
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //ofset
                for(int k=ans;k<min(n-i,m-j);k++){
                    int row = i+k;
                    int col = j+k;
                    int sum = findSum(i,j,row,col,prefixSum);
                    if(sum<=threshold){
                        ans = max(ans,k+1);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};