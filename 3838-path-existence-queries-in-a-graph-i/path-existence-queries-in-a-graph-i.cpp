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
            if(rank[p1]<rank[p2]){
                parent[p1] = p2;
            }
            else if(rank[p2]<rank[p1]){
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);
        vector<bool>result;
        int i=0;
        int j=0;
        while(j<nums.size()){
            int diff = abs(nums[i] - nums[j]);
            if(diff<=maxDiff){
                dsu.unionByRank(i, j);
                j++;
            }
            else{
                i++;
            }
        }
        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if(dsu.find(u) == dsu.find(v)){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }
};