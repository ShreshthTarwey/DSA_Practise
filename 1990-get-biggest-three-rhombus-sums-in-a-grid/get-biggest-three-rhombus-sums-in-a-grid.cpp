class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<int>st;
        auto addSet = [&](int sum){
            st.insert(sum);
            if(st.size()>3){
                st.erase(st.begin());
            }
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                addSet(grid[i][j]);
                //sides
                for(int side = 1;i-side>=0 && i+side<n && j-side>=0 && j+side<m;side++){
                    int sum = 0;
                    for(int k=0;k<=side-1;k++){
                        sum+= grid[i-side+k][j+k];
                        sum+= grid[i+k][j+side-k];
                        sum+= grid[i+side-k][j-k];
                        sum+=grid[i-k][j-side+k];
                    }
                    addSet(sum);
                }
            }
        }
        vector<int>ans;
        for(auto &it: st){
            ans.push_back(it);
        }
        sort(ans.rbegin(), ans.rend());
        return ans;
    }
};