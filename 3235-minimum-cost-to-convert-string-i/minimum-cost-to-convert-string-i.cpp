class Solution {
public:
    long long floydWarshellALgo(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        vector<vector<long long>>adjMatrix(26, vector<long long>(26, INT_MAX)); //We use adjcency Matrix on floyd warshell
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
    void dijkstra(char source, unordered_map<char, vector<pair<int, char>>>&adjList, vector<vector<int>>&costMatrix){
        //min-heap
        priority_queue<pair<int, char>, vector<pair<int,char>>, greater<pair<int, char>>>pq;
        pq.push({0, source});
        while(!pq.empty()){
            int cost1 = pq.top().first;
            char adjNode = pq.top().second;
            pq.pop();
            for(auto it: adjList[adjNode]){
                char adjNode2 = it.second;
                int cost2 = it.first;
                if(costMatrix[source-'a'][adjNode2-'a']>cost2+cost1){
                    costMatrix[source-'a'][adjNode2-'a'] = cost2+cost1;
                    pq.push({cost2+cost1, adjNode2});
                }
            }
        }
    }
    long long dijkstraAlgo(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        unordered_map<char, vector<pair<int, char>>>adjList;
        for(int i=0;i<original.size();i++){
            adjList[original[i]].push_back({cost[i], changed[i]});
        }

        // now creating 2d matrix for storing the values that dijkstra will give for every source to every node
        vector<vector<int>>costMatrix(26, vector<int>(26, INT_MAX));

        //Now populating the costMatrix

        for(int i=0;i<source.length();i++){
            char ch = source[i];
            dijkstra(ch, adjList, costMatrix);
        }

        long long ans = 0;
        for(int i=0;i<source.length();i++){
            int ch1 = source[i];
            int ch2 = target[i];
            if(ch1 == ch2) continue;
            long long c = costMatrix[ch1-'a'][ch2-'a'];
            if(c==INT_MAX) return -1;
            ans+=c;
        }
        return ans;

    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //Method 1 - Floyd Warshell, recommended for this question
        // return floydWarshellALgo(source, target, original, changed, cost); //T.C-> O(n) since 3 nested loops are only runinning 26 time so we are assuming linear time complexity
    
        //Method 2 -> Dijkstra Algo 
        return dijkstraAlgo(source, target, original, changed, cost);

    }
};