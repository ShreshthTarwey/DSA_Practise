class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int layers = min(n/2, m/2);
        for(int layer = 0; layer<layers;layer++){
            int top = layer;
            int bottom = n-1-layer;
            int left = layer;
            int right = m-1-layer;
            vector<int>nums;
            //First from left to right
            for(int j=left;j<=right;j++){
                nums.push_back(grid[top][j]);
            }
            //From right to bottom
            for(int j=top+1;j<=bottom;j++){
                nums.push_back(grid[j][right]);
            }
            //From bottom to left
            for(int j=right-1;j>=left;j--){
                nums.push_back(grid[bottom][j]);
            }
            //From bottom to top
            for(int j=bottom-1;j>top;j--){
                nums.push_back(grid[j][left]);
            }
            int size = nums.size();
            int rotations = k%size;
            //Now rotation
            for(int i=0;i<rotations;i++){
                int temp = nums[0];
                for(int j=0;j<nums.size()-1;j++){
                    nums[j] = nums[j+1];
                }
                nums[nums.size()-1] = temp;
            }
            int index = 0;
            //First from left to right
            for(int j=left;j<=right;j++){
                // nums.push_back(grid[top][j]);
                grid[top][j] = nums[index++];
            }
            //From right to bottom
            for(int j=top+1;j<=bottom;j++){
                // nums.push_back(grid[j][right]);
                grid[j][right] = nums[index++];
            }
            //From bottom to left
            for(int j=right-1;j>=left;j--){
                // nums.push_back(grid[bottom][j])
                grid[bottom][j] = nums[index++];
            }
            //From bottom to top
            for(int j=bottom-1;j>top;j--){
                // nums.push_back(grid[j][left]);
                grid[j][left] = nums[index++];
            }
        }
        return grid;
    }
};