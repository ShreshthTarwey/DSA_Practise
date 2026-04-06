class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        rank.resize(n, 0);
        parent.resize(n);
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
    bool unionByRank(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        if(parent_x != parent_y){
            if(rank[parent_x]>rank[parent_y]){
                parent[parent_y] = parent_x;
            }
            else if(rank[parent_x]<rank[parent_y]){
                parent[parent_x] = parent_y;
            }
            else{
                parent[parent_x] = parent_y;
                rank[parent_y]++;
            }
            return false;
        }
        else{
            return true;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for(auto st: equations){
            if(st[1]=='='){
                dsu.unionByRank(st[0]-'a', st[3]-'a');
            }
        }
        for(auto st: equations){
            if(st[1] == '!'){
                int parent_a = dsu.find(st[0]-'a');
                int parent_b = dsu.find(st[3]-'a');
                if(parent_a == parent_b){
                    return false;
                }
            }
        }
        return true;
    }
};