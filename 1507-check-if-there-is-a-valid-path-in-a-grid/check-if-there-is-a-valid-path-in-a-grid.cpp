class Solution {
public:
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, unordered_map<int, vector<vector<int>>>& mp, int i, int j){
        int n=grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m || i<0 || j<0) return false;
        if(i==n-1 && j==m-1) return true;
        if(visited[i][j]) return false;
        visited[i][j] = true;
        for(auto &it: mp[grid[i][j]]){
            int new_i = i + it[0];
            int new_j = j + it[1];
             if(new_i < 0 || new_j < 0 || new_i >= n || new_j >= m)
                continue;
            for(auto &back: mp[grid[new_i][new_j]]){
                if(new_i + back[0] == i && new_j + back[1] == j){
                    if(dfs(grid, visited, mp, new_i, new_j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        unordered_map<int, vector<vector<int>>>mp;
        mp[1] = {{0,-1},{0,1}};
        mp[2] = {{-1,0},{1,0}};
        mp[3] = {{0,-1},{1,0}};
        mp[4] = {{1,0},{0,1}};
        mp[5] = {{0,-1},{-1,0}};
        mp[6] = {{-1,0},{0,1}};
        return dfs(grid, visited,mp,0, 0);
    }
};