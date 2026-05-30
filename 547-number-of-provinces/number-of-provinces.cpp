class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, int idx, vector<bool>& visited){
        if(visited[idx]) return;
        visited[idx] = true;
        queue<int>q;
        q.push(idx);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<isConnected.size();i++){
                if(isConnected[node][i] && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n, false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                bfs(isConnected, i, visited);
            }
        }
        return count;
    }
};