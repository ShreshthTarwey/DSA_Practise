class Solution {
public:
    bool check(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        long long totalSum = 0;
        for(auto &it: grid){
            totalSum += accumulate(it.begin(), it.end(), (long long)0);
        }

        unordered_set<long long>st;
        long long top = 0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                top += grid[i][j];
                st.insert(grid[i][j]);
            }
            long long bottom = totalSum - top;
            long long diff = top-bottom;
            if(diff == 0) return true;
            if(diff == grid[0][0]) return true;
            if(diff == grid[0][m-1]) return true;
            if(diff == grid[i][0]) return true;
            if(i>0 && m>1 && st.count(diff)) return true;
        }
        return false;
    }
    void transpose(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>result(m, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[j][i] = grid[i][j];
            }
        }
        grid = result;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(check(grid)){
            return true;
        }
        reverse(grid.begin(), grid.end());
        if(check(grid)){
            return true;
        }
        transpose(grid);
        if(check(grid)){
            return true;
        }
        reverse(grid.begin(), grid.end());
        if(check(grid)){
            return true;
        }
        return false;
    }
};