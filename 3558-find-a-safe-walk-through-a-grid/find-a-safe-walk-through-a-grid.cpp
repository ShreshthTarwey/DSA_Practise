class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>>q;
        q.push_back({0, 0});
        dist[0][0] = grid[0][0];
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop_front();
            if(x == n-1 && y == m-1){
                return true;
            }
            for(auto &[dx, dy] : DIRS){
                int nx = x + dx;
                int ny = y + dy;
                if(nx<0 || ny<0 || nx>=n || ny>=m){
                    continue;
                }
                int cost = dist[x][y] + grid[nx][ny];
                if(cost>=health) continue;
                if(cost<dist[nx][ny]){
                    dist[nx][ny] = cost;
                    if(grid[nx][ny] == 0){
                        q.push_front({nx, ny});
                    }
                    else{
                        q.push_back({nx, ny});
                    }
                }
            }
        }
        return false;
    }
};