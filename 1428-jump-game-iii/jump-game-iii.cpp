class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // unordered_map<int, int>mp;
        int n = arr.size();
        queue<int>q;
        q.push(start);
        vector<bool>visited(n, false);
        visited[start] = true;
        while(!q.empty()){
            int index = q.front();
            q.pop();
            if(arr[index] == 0){
                return true;
            }
            if(index + arr[index]<n && !visited[index + arr[index]]){
                visited[index + arr[index]] = true;
                q.push(index+arr[index]);
            }
            if(index - arr[index]>=0 && !visited[index - arr[index]]){
                visited[index - arr[index]] = true;
                q.push(index - arr[index]);
            }
        }
        return false;
    }
};