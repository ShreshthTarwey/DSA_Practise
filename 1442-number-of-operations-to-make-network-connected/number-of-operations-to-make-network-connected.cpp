class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    int components;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        components = n;
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
            if(rank[p1]<rank[p2]){
                parent[p1] = p2;
            }
            else if(rank[p1]>rank[p2]){
                parent[p2] = p1;
            }
            else{
                parent[p1] = p2;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        DSU dsu(n);
        for(auto &it: connections){
            dsu.unionByRank(it[0], it[1]);
        }

        return dsu.getComponents() - 1;
    }
};