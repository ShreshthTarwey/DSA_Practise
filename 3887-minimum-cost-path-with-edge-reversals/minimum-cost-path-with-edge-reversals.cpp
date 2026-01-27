class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<int>>newEdges = edges;
        for(auto it: edges){
            int source = it[0];
            int dest = it[1];
            int dist = it[2] * 2;
            newEdges.push_back({dest, source, dist});
        }

        vector<vector<pair<int,int>>>abc(n);

        for(auto it: newEdges){
            int node = it[0];
            int dest = it[1];
            int cost = it[2];

            abc[node].push_back({dest, cost});
        }



        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        vector<int>result(n,INT_MAX);

        int source = 0;

        result[source] = 0;

        pq.push({0, source});

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: abc[node]){
                // for(auto jt: it){
                    int distance = it.second;
                    int dest = it.first;

                    if(distance+d<result[dest]){
                        pq.push({distance+d, dest});
                        result[dest] = distance+d;
                    }
                // }

            }
        }


        return result[n-1] == INT_MAX ? -1 : result[n-1];



    }
};