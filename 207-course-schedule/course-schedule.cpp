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
    bool method2(int numCourses, vector<vector<int>>& prerequisites){
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>adjList(numCourses);
        for(auto &it: prerequisites){
            adjList[it[0]].push_back(it[1]);
        }
        //Filling indegree
        for(auto &it : adjList){
            for(auto &jt: it){
                indegree[jt]++;
            }
        }
        queue<int>q;
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
            for(auto it: adjList[node]){
                indegree[it]--;
                if(!indegree[it]){
                    q.push(it);
                }
            }
        }
        return temp.size() == numCourses;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // return method1(numCourses, prerequisites); //DFS on Directed Graph
        return method2(numCourses, prerequisites); //BFS on Directed Graph, Also known as khan's algorithm
    }
};