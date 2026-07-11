class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    DSU(int x){
        parent.resize(x);
        rank.resize(x, 0);
        for(int i=0;i<x;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unionByRank(int a, int b){
        int p1 = find(a);
        int p2 = find(b);
        if(p1 != p2){
            if(rank[p2]>rank[p1]){
                parent[p1] = p2;
            }
            else if(rank[p1]>rank[p2]){
                parent[p2] = p1;
            }
            else{
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    }
};
class Solution {
public:
    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int node, int &count, int &m){
        visited[node] = true;
        m++;
        for(auto &it: adjList[node]){
            count++;
            if(!visited[it]){
                dfs(adjList, visited, it, count, m);
            }
        }

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n);
        for(auto &it: edges){
            // dsu.unionByRank(it[0], it[1]);
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        vector<bool>visited(n, false);
        int ans = 0;
        //Using Disjoint Set Union------------------------> Method 1
        // DSU dsu(n);
        // unordered_map<int, vector<int>>mp;
        // for(int i=0;i<n;i++){
        //     int root = dsu.find(i);
        //     mp[root].push_back(i);
        // }
        // //Doing BFS from every parent
        // for(auto &it: mp){
        //     int root = it.first;
        //     visited[root] = true;
        //     int edgeCount = 0;
        //     int m = it.second.size();
        //     //Doing BFS from parent
        //     queue<int>q;
        //     q.push(root);
        //     int count = 0;
        //     while(!q.empty()){
        //         int node = q.front();
        //         q.pop();
        //         for(auto &it: adjList[node]){
        //             if(!visited[it]){
        //                 visited[it] = true;
        //                 q.push(it);
        //             }
        //             count++;
        //         }
        //     }
        //     if(count/2 == (m * (m-1)/2)){
        //         ans++;
        //     }
        // }
        // return ans;

        //Method 2--------------------------------------->BFS
        // for(int i=0;i<n;i++){
        //     if(!visited[i]){
        //         visited[i] = true;
        //         queue<int>q;
        //         q.push(i);
        //         int count = 0;
        //         int m = 0;
        //         while(!q.empty()){
        //             int node = q.front();
        //             m++;
        //             q.pop();
        //             for(auto &it: adjList[node]){
        //                 count++;
        //                 if(!visited[it]){
        //                     q.push(it);
        //                     visited[it] = true;
        //                 }
        //             }
        //         }
        //         if(count/2 == (m*(m-1)/2)){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        //Method 3---------------------------------->DFS
        for(int i=0;i<n;i++){
            int count = 0;
            int m = 0;
            if(!visited[i]){
                visited[i] = true;
                dfs(adjList, visited, i, count, m);
                if(count/2 == (m*(m-1)/2)){
                    ans++;
                }
            }

        }
        return ans;

    }
};