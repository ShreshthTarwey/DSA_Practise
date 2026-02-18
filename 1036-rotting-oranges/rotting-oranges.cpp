class Solution {
public:
    void mark(vector<vector<int>>& temp, vector<vector<int>>& grid, int i, int j,bool &change){
        //up firsction
        if(i>0 && temp[i-1][j]!=0 && temp[i-1][j]!=2){
            grid[i-1][j] = 2;
            change = true;
        }
        //Down direction
        if(i<grid.size()-1 && temp[i+1][j]!=0 && temp[i+1][j]!=2){
            change = true;
            grid[i+1][j] = 2;
        }
        //Left direction
        if(j>0 && temp[i][j-1]!=0 && temp[i][j-1]!=2){
            change = true;
            grid[i][j-1] = 2;
        }
        // right direction
        if(j<grid[0].size()-1 && temp[i][j+1]!=0 && temp[i][j+1]!=2){
            change = true;
            grid[i][j+1] = 2;
        }
        // grid = temp;
        return;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        while(true){
            vector<vector<int>> temp = grid;
            bool change = false;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(temp[i][j]==2){
                        mark(temp,grid,i,j,change);
                    }
                }
            }
            
            if(!change) break;
            minutes++;

        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minutes;
        
    }
};