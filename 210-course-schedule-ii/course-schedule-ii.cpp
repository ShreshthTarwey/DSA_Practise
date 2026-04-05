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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return khansAlgo(numCourses, prerequisites);
    }
};