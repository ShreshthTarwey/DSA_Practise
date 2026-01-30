class Solution {
public:
    typedef long long ll;
    unordered_map<string, vector<pair<string, ll>>>adjList; //Graph

    ll BIG_VAL = 1e10;
    vector<ll>dpMemo;
    // start -> end ->ans
    unordered_map<string, unordered_map<string, ll>>dijkstraMemo; 

    set<ll>validLengths;
    string src;
    string trg;

    ll dijkstra(string start, string dest){
        priority_queue<pair<ll,string>, vector<pair<ll,string>>, greater<pair<ll, string>>>pq;
        
        if(dijkstraMemo[start].count(dest)){
            return dijkstraMemo[start][dest];
        }
        
        //We are not using vector here, since nodes are string here so that's why

        unordered_map<string, ll>result;

        result[start] = 0;
        pq.push({0, start});

        while(!pq.empty()){
            ll cost = pq.top().first;
            string node = pq.top().second;
            pq.pop();
            for(auto it: adjList[node]){
                ll cost2 = it.second;
                string dest2 = it.first;
                if(!result.count(dest2) || cost + cost2 < result[dest2]){
                    result[dest2] = cost + cost2;
                    pq.push({cost+cost2, dest2});
                }
            }
        }
        return dijkstraMemo[start][dest] = result.count(dest) ? result[dest] : BIG_VAL;
    }

    long long solve(int i){
        if(i>=src.length()){
            return 0;
        }
        if(dpMemo[i]!=-1) return dpMemo[i];
        ll result = BIG_VAL;
        //Option1
        if(src[i] == trg[i]){
            result = solve(i+1);
        }

        for(auto it: validLengths){
            if(it + i> src.length()){
                break;
            }
            string start = src.substr(i, it);
            string dest = trg.substr(i, it);

            if(!adjList.count(start)) continue;

            ll pathCost = dijkstra(start, dest);
            if(pathCost == BIG_VAL) continue;
            result = min(result, pathCost + solve(i+it));
        }
        return dpMemo[i] = result;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        src = source;
        trg = target;
        dpMemo.assign(1001, -1);

        //Fill graph
        for(int i=0;i<original.size();i++){
            adjList[original[i]].push_back({changed[i], cost[i]});
            validLengths.insert(original[i].length());
        }

        ll ans = solve(0);
        return ans==BIG_VAL ? -1 : ans;


    }
};