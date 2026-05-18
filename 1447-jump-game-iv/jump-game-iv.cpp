class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool>visited(n, false);
        queue<int>q;
        q.push(0);
        visited[0] = true;
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
               int curr = q.front();
                q.pop();
                if(curr == n-1){
                    return steps;
                }
                if(curr - 1>=0 && !visited[curr - 1]){
                    visited[curr - 1] = true;
                    q.push(curr-1);
                }
                if(curr + 1<n && !visited[curr + 1]){
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                for(auto &idx: mp[arr[curr]]){
                    q.push(idx);
                    visited[idx] = true;
                }
                mp.erase(arr[curr]);
            }
            steps++;
        }
        return -1;
    }
};