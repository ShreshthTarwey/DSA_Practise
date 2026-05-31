class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    DSU(int V){
        rank.resize(V, 0);
        parent.resize(V);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
    }
    
    int find(int u){
        if(parent[u] != u){
            parent[u] = find(parent[u]);
        }
        return parent[u];
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
                parent[p1] = p2;
                rank[p2]++;
            }
        }
    }
};
class Solution {
public:
    int kruskals(vector<vector<int>>& vec){
        int n = vec.size();
        DSU dsu(n);
        int sum = 0;
        for(int i=0;i<n;i++){
            int u = vec[i][0];
            int v = vec[i][1];
            int wt = vec[i][2];
            if(dsu.find(u) != dsu.find(v)){
                sum += wt;
                dsu.unionByRank(u, v);
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>vec;
        for(int i=0;i<points.size();i++){
            int xi = points[i][0];
            int yi = points[i][1];
            for(int j=0;j<points.size();j++){
                int xj = points[j][0];
                int yj = points[j][1];
                vec.push_back({i, j, (abs(xi - xj) + abs(yi - yj))});
            }
        }
        auto comparator = [&](vector<int>& v1, vector<int>& v2){
            return v1[2] < v2[2];
        };
        sort(vec.begin(), vec.end(), comparator);
        return kruskals(vec);
    }
};