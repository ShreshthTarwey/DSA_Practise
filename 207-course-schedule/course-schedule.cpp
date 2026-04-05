class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& pathVisited){
        visited[node] = true;
        pathVisited[node] = true;
        for(auto n: adjList[node]){
            if(!visited[n]){
                if(dfs(n, adjList, visited, pathVisited)){
                    return true;
                }
            }
            else if(pathVisited[n]){
                return true;
            }
        }
        pathVisited[node] = false;
        return false;
    }
    bool method1(int numCourses, vector<vector<int>>& prerequisites){
        vector<bool>visited(numCourses, false);
        vector<bool>pathVisited(numCourses, false);
        vector<vector<int>>adjList(numCourses);
        for(auto &it: prerequisites){
            adjList[it[0]].push_back(it[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
                if(dfs(i, adjList, visited, pathVisited)){
                return false;
                }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return method1(numCourses, prerequisites); //DFS on Directed Graph

    }
};