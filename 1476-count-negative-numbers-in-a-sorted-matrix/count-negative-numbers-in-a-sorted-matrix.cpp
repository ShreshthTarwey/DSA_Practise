class Solution {
public:
    int myMethod(vector<vector<int>>& grid){
        int count = 0;
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[0].size()-1;j>=0;j--){
                if(grid[i][j]>=0) break;
                count++;
            }
        }
        return count;
    }

    int optimizedMethod(vector<vector<int>>& grid){
        int count = 0;
        int row = grid.size()-1;
        int col = 0;
        while(row>=0 && col<grid[0].size()){
            if(grid[row][col]<0){
                count += (grid[0].size() - col );
                row--;
            }
            else{
                col++;
            }
        }
        return count;
    }
    int countNegatives(vector<vector<int>>& grid) {
        // return myMethod(grid); //O(N*M)
        return optimizedMethod(grid);
    }
};