class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans(n-k+1, vector<int>(m-k+1));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                set<int>st;
                for(int l=i;l<i+k;l++){
                    for(int o=j;o<j+k;o++){
                        st.insert(grid[l][o]);
                    }
                }
                int min_diff = INT_MAX;
                auto it = st.begin();
                int num = *it;
                it++;
                while(it!=st.end()){
                    min_diff = min(min_diff, abs(num - *it));
                    num = *it;
                    it++;
                }
                if(min_diff!=INT_MAX)
                    ans[i][j] = min_diff;
            }
        }
        return ans;
    }
};