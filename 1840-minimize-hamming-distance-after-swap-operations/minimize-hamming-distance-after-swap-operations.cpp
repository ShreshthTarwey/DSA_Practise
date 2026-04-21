class DSU{
    vector<int>parent;
    vector<int>rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unionByRank(int x, int y){
        int p1 = find(x);
        int p2 = find(y);
        if(p1 != p2){
            if(rank[p1]>rank[p2]){
                parent[p2] = p1;
            }
            else if(rank[p1]<rank[p2]){
                parent[p1] = p2;
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
    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& components, int node){
        visited[node] = true;
        components.push_back(node);
        for(auto &it: adjList[node]){
            if(!visited[it]){
                dfs(adjList, visited, components, it);
            }
        }
    }
    int dfsMethod(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps){
        int n = source.size();
        int mismatch = 0;
        vector<vector<int>>adjList(n);
        for(auto &it: allowedSwaps){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        vector<bool>visited(n, false);
        vector<int>components;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                components.clear();
                dfs(adjList, visited, components, i);
                //Now we have all elements of one component in this array
                unordered_map<int, int>mp;
                for(auto &it: components){
                    mp[source[it]]++;
                }
                //Now going to satisfy target value with help of source map
                for(auto idx: components){
                    if(mp[target[idx]]){
                        mp[target[idx]]--;
                    }
                    else{
                        mismatch++;
                    }
                }
            }
        }
        return mismatch;
    }
    int dsuMethod(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps){
        int n = source.size();
        int mismatch = 0;
        DSU dsu(n);
        unordered_map<int, unordered_map<int, int>>mp;
        for(auto &it: allowedSwaps){
            dsu.unionByRank(it[0], it[1]);
        }
        for(int i=0;i<n;i++){
            mp[dsu.find(i)][source[i]]++;
        }
        for(int i=0;i<n;i++){
            int parent = dsu.find(i);
            if(mp[parent][target[i]]>=1){
                mp[parent][target[i]]--;
            }
            else{
                mismatch++;
            }
        }
        return mismatch;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        // return dfsMethod(source, target, allowedSwaps);
        return dsuMethod(source, target, allowedSwaps);
    }
};