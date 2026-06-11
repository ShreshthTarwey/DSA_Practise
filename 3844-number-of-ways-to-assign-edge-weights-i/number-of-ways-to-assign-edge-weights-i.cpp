class Solution {
public:
    const int MOD = 1e9+7;
    int dfs(vector<vector<int>>& adjList, int node, int parent){
        int maxDepth = 0;
        for(auto &neigh: adjList[node]){
            if(neigh == parent) continue;
            maxDepth = max(maxDepth, dfs(adjList, neigh, node)+1);
        }
        return maxDepth;
    }
    long long modPow(long long a, long long b){
        long long res = 1;
        while(b){
            if(b&1) res = (res * a)%MOD;
            a = (a * a)%MOD;
            b = b/2;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adjList(n+2);
        for(auto &it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        int maxDepth = dfs(adjList, 1, -1);
        return modPow(2, maxDepth-1);
    }
};