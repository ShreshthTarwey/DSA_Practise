class Solution {
public:
    bool isPossible(vector<vector<int>>& dist, int val, int i, int j, vector<vector<bool>>& visited){
        int n = dist.size();
        int m = dist[0].size();
        if(i>=n || j>=m || i<0 || j<0) return false;
        if(i==n-1 && j==m-1){
            return dist[i][j] >= val;
        }
        if(visited[i][j]) return false;
        if(dist[i][j]<val) return false;
        visited[i][j] = true;
        bool option1 = isPossible(dist, val, i, j-1, visited);
        bool option2 = isPossible(dist, val, i, j+1, visited);
        bool option3 = isPossible(dist, val, i+1, j, visited);
        bool option4 = isPossible(dist, val, i-1, j, visited);

        return option1 || option2 || option3 || option4;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int d = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second;
                if(y+1<m && dist[x][y+1] == -1){
                    dist[x][y+1] = d;
                    q.push({x, y+1});
                }
                if(y-1>=0  && dist[x][y-1] == -1){
                    dist[x][y-1] = d;
                    q.push({x, y-1});
                }
                if(x+1<n && dist[x+1][y] == -1){
                    dist[x+1][y] = d;
                    q.push({x+1, y});
                }
                if(x-1>=0 && dist[x-1][y] == -1){
                    dist[x-1][y] = d;
                    q.push({x-1, y});
                }
            }
            d++;
        }
        //Do binary search
        int l = 0;
        int r = max(n,m);
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            vector<vector<bool>>visited(n, vector<bool>(m, false));
            // visited[0][0] = true;
            if(isPossible(dist, mid, 0, 0, visited)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};