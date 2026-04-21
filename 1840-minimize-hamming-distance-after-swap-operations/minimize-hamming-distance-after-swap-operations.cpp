
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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
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
};