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
    void unionByRank(int x, int y){
        int parent_a = find(x);
        int parent_b = find(y);
        if(parent_a != parent_b){
            if(rank[parent_a]>rank[parent_b]){
                parent[parent_b] = parent_a;
            }
            else if(rank[parent_b]>rank[parent_a]){
                parent[parent_b] = parent_a;
            }
            else{
                parent[parent_a] = parent_b;
                rank[parent_a]++;
            }
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, int>mp;
        DSU dsu(n);
        for(auto it: edges){
            dsu.unionByRank(it[0], it[1]);
        }
        for(int i=0;i<n;i++){
            mp[dsu.find(i)]++;
        }
        long long res = 0;
        long long rem = n;
        for(auto it : mp){
            res += it.second * (rem - it.second);
            rem -= it.second;
        }
        return res;
    }
};