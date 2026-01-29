class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>adjMatrix(26, vector<long long>(26, INT_MAX));
        for(int i=0;i<original.size();i++){
            adjMatrix[original[i] - 'a'][changed[i] - 'a'] = adjMatrix[original[i] - 'a'][changed[i] - 'a']>cost[i] ? cost[i] : adjMatrix[original[i] - 'a'][changed[i] - 'a'];
        }
        //Applyting floyd warshell algo
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] +  adjMatrix[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<source.length();i++){
            if(source[i] == target[i]){
                continue;
            }
            else{
                long long c = adjMatrix[source[i] - 'a'][target[i]-'a'];
                if(c == INT_MAX) return -1;
                ans+=c;
            }
        }
        return ans;
    }
};