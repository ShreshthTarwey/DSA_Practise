class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int node){
        for(auto ch : graph[node]){
            if(vis[ch] == 0){
                vis[ch] = (vis[node] == 1? 2: 1);
                if(!dfs(graph, vis, ch)) 
                    return false;
            }
            else{
                if(vis[ch] == vis[node]){
                    return false;
                }

            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, 0);
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                vis[i] = 1;
                if(dfs(graph, vis, i) == false) return false;
            }
        }
        return true;
    }
};