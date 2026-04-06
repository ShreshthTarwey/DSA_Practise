class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    int components;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        components = n;
    }
    int find(int x){
        if(parent[x] != x){
            parent[x]  = find(parent[x]);
        }
        return parent[x];
    }
    void unionByRank(int x, int y){
        int parent_a = find(x);
        int parent_b = find(y);
        if(parent_a != parent_b){
            if(rank[parent_a]>rank[parent_b]){
                parent[parent_b] = parent_a;
            }
            else if(rank[parent_b]>rank[parent_a]){
                parent[parent_a]  = parent_b;
            }
            else{
                parent[parent_b] = parent_a;
                rank[parent_a]++;
            }
            components--;
        }
    }
    int getComponents(){
        return components;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU dsu(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j])
                    dsu.unionByRank(i, j);
            }
        }
        return dsu.getComponents();
    }
};