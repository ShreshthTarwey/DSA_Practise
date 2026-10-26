class Solution {
public:
    void isIsIslandAndDivisibleMark(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i,int j,int k,long long &sum){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0) return;
        if(visited[i][j] || grid[i][j]==0) return;
        
        visited[i][j] = true;
        sum+=grid[i][j];
        isIsIslandAndDivisibleMark(grid,visited,i,j+1,k,sum); //Right direction
        isIsIslandAndDivisibleMark(grid,visited,i+1,j,k,sum); //Down direction
        isIsIslandAndDivisibleMark(grid,visited,i,j-1,k,sum); //Left direction
        isIsIslandAndDivisibleMark(grid,visited,i-1,j,k,sum); //Up direction
        return;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count = 0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum=0;
                if(!visited[i][j] && grid[i][j]!=0){
                    isIsIslandAndDivisibleMark(grid,visited,i,j,k,sum);
                    if(sum%k==0) count++;
                }
            }
        }
        return count;
    }
};