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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int>mailToNode;
        DSU ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mailToNode.find(mail)==mailToNode.end()){
                    mailToNode[mail] = i;
                }
                else{
                    ds.Union(mailToNode[mail], i);
                }
            }
        }
        vector<vector<string>>mergedMail(n);
        for(auto it: mailToNode){
            string mail = it.first;
            int node = ds.find(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};