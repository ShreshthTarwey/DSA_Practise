class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adjList(n);
        queue<int>q;
        vector<bool>visited(n, false);
        for(auto &it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int node = q.front();
            if(node == destination){
                return true;
            }
            q.pop();
            for(auto &it: adjList[node]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};