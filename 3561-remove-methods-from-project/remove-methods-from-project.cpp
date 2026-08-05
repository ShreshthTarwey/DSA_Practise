class Solution {
public:
    void dfs(vector<vector<int>>& adjList, int node, vector<bool>& suspicious){
        if(suspicious[node]){
            return;
        }
        suspicious[node] = true;
        for(int child: adjList[node]){
            dfs(adjList, child, suspicious);
        }
    }

    // void dfs2(vector<vector<int>>& adjList, int node, vector<bool>& visited, vector<bool>& suspicious){
    //     if(visited[node]){
    //         return;
    //     }
    //     suspicious[node] = false;
    //     visited[node] = true;
    //     for(int child: adjList[node]){
    //         dfs2(adjList, child, visited, suspicious);
    //     }
    // }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool>suspicious(n, false);
        vector<vector<int>>adjList(n);
        for(auto &it: invocations){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
        }

        dfs(adjList, k, suspicious);

        vector<bool>visited(n, false);

        // for(int i=0;i<n;i++){
        //     if(!visited[i] && !suspicious[i]){
        //         dfs2(adjList, i, visited, suspicious);
        //     }
        // }

        for(auto &it: invocations){
            int u = it[0];
            int v = it[1];
            if(!suspicious[u] && suspicious[v]){
                vector<int>ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!suspicious[i]){
                ans.push_back(i);
            }
        }
        return ans;

    }
};