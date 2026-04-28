class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int target = arr[size/2];
        int count = 0;
        for(auto &num: arr){
            if(target % x != num % x){
                return -1;
            }
            count += (abs(target - num)/x);
        }
        return count;
    }
};