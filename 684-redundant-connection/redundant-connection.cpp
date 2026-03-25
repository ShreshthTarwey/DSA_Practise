class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int n){
        if(parent[n] != n){
            return parent[n] = find(parent[n]);
        }
        return n;
    }
    bool Union(int x, int y){
        int p1 = find(x);
        int p2 = find(y);
        if(p1 == p2){
            return false;
        }

        if(rank[p1]>rank[p2]){
            parent[p2] = p1;
        }
        else if(rank[p1]<rank[p2]){
            parent[p1] = p2;
        }
        else{
            parent[p1] = p2;
            rank[p2]++;
        }
        return true;

    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU *obj = new DSU(edges.size()+1);
        for(auto &it: edges){
            if(!obj->Union(it[0], it[1])){
                return {it[0], it[1]};
            }
        }
        return {0, 0};
    }
};