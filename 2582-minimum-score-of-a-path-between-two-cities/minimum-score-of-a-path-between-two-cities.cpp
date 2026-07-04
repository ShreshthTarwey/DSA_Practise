class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
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
    void unionByRank(int a, int b){
        int p1 = find(a);
        int p2 = find(b);
        if(p1 != p2){
            if(rank[p1]>rank[p2]){
                parent[p2] = p1;
            }
            else if(rank[p2]>rank[p1]){
                parent[p1] = p2;
            }
            else{
                parent[p2] = p1;
            }
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n+1);
        for(auto &it: roads){
            dsu.unionByRank(it[0], it[1]);
        }
        int ans = INT_MAX;;
        int p = dsu.find(1);
        for(auto &it: roads){
            if(p  == dsu.find(it[0])){
                ans = min(ans, it[2]);
            }
        }
        return ans;
    }
};