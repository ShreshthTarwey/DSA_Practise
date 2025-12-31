class Solution {
public:
    bool canReach(vector<vector<int>>& mat, vector<vector<bool>>& visited, int i, int j){
        
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()) return false;
        if(mat[i][j] == 1) return false;
        if(visited[i][j]) return false;
        if(i==mat.size()-1) return true;

        visited[i][j] = true;
        bool left = canReach(mat, visited, i, j-1);
        bool right = canReach(mat, visited, i, j+1);
        bool up = canReach(mat, visited, i-1, j);
        bool down = canReach(mat, visited, i+1, j);

        // visited[i][j] = false;

        return (left || right || down || up);
    }
    int fullBruteForceMyMethod(int row, int col, vector<vector<int>>& cells){
        vector<vector<int>>mat(row, vector<int>(col, 0));
        int lastDay = 0;

        //Water krr doo


        for(int i=0;i<cells.size();i++){
            //Water krr doo
            mat[cells[i][0]-1][cells[i][1]-1] = 1;
            bool flag = false;

            for(int j=0;j<mat[0].size();j++){
                // int startPoint =  mat[0][j];
                vector<vector<bool>>visited(row, vector<bool>(col, false));
                if(canReach(mat, visited, 0, j)){
                    lastDay = i+1;
                    flag = true;
                }
            }

            if(!flag) break;
        }
        return lastDay;
    }

    bool canCross(int row, int col, int mid, vector<vector<int>>& cells){
        vector<vector<int>>grid(row, vector<int>(col, 0));

        //Pani bharo

        for(int i=0;i<=mid;i++){
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        vector<vector<bool>>visited(row, vector<bool>(col, false));

        for(int i=0;i<col;i++){
            if(canReach(grid, visited, 0, i)){
                return true;
            }
        }

        return false;

    }


    int binarySearchApproach(int row, int col, vector<vector<int>>& cells){
        int l = 0;
        int r = cells.size();
        int lastDay = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(canCross(row, col, mid, cells)){
                l = mid+1;
                lastDay = mid + 1;
            }
            else{
                r = mid-1;
            }
        }
        return lastDay;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // return fullBruteForceMyMethod(row, col, cells);//TLE is coming O(N^2)
        return binarySearchApproach(row, col, cells);
    }
};