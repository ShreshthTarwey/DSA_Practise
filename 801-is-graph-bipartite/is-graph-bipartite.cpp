class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& color, int c){
        color[node] = c;
        c = 1 - c;
        for(auto &it: graph[node]){
            if(color[it] == color[node]) return false;
            if(color[it] == -1){
            if(!dfs(graph, it, color, c)){
                return false;
            }

            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!dfs(graph, i, color, 1)){
                    return false;
                }
            }
        }
        return true;
    }
};