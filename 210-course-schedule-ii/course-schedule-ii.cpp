class Solution {
public:
    vector<int>khansAlgo(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>>adjList(numCourses);
        for(auto &it: prerequisites){
            adjList[it[1]].push_back(it[0]);
        }
        vector<int>indegree(numCourses, 0);
        queue<int>q;
        for(auto &it: adjList){
            for(auto &jt: it){
                indegree[jt]++;
            }
        }
        for(int i=0;i<indegree.size();i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        vector<int>temp;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            temp.push_back(node);
            for(auto &it: adjList[node]){
                indegree[it]--;
                if(!indegree[it]){
                    q.push(it);
                }
            }
        }
        return temp.size() == numCourses ? temp : vector<int>();
    }
    bool dfs(vector<vector<int>>& adjList, int node, vector<bool>& visited, stack<int>& st, vector<bool>& pathVisited){
        
        visited[node] = true;
        pathVisited[node] = true;
        for(auto &it: adjList[node]){
            if(!visited[it]){
                if(dfs(adjList, it, visited, st, pathVisited)){
                    return true;
                }
            }
            else if(pathVisited[it]){
                return true;
            }
        }
        st.push(node);
        pathVisited[node] = false;
        return false;
    }
    vector<int> usingDFS(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>>adjList(numCourses);
        for(auto &it: prerequisites){
            adjList[it[1]].push_back(it[0]);
        }
        vector<int>res;
        stack<int>st;
        vector<bool>visited(numCourses, false);
        vector<bool>pathVisited(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(adjList, i, visited, st, pathVisited)){
                    return vector<int>();
                }
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res.size() == numCourses ? res : vector<int>();
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // return khansAlgo(numCourses, prerequisites);
        return usingDFS(numCourses, prerequisites);
    }
};