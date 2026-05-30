class Solution {
public:
    void dfs(vector<vector<int>>& adjList, int idx, vector<bool>& visited){
        if(visited[idx]) return;
        visited[idx] = true;
        for(auto &it: adjList[idx]){
            dfs(adjList, it, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adjList(n);
        vector<bool>visited(n, false);
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                // visited[i] = true;
                dfs(adjList, i, visited);
                count++;
            }
        }
        return count;
    }
};