class Solution {
public:
    int findSpace(vector<char>& arr, int x){
        int res = x;
        while(res>=0){
            if(arr[res] == '.'){
                return res;
            }
            res--;
        }
        return res;
    }
    vector<vector<char>> rotate(vector<vector<char>>& boxGrid){
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>>matrix(m, vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[j][n-i-1] = boxGrid[i][j];
            }
        }
        return matrix;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        for(int i=0;i<n;i++){
            int space = m-1;
            for(int j=m-1;j>=0;j--){
                if(boxGrid[i][j] == '*'){
                    space = j-1;
                }
                else if(boxGrid[i][j] == '#'){
                    swap(boxGrid[i][j], boxGrid[i][space]);
                    space--;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     int space = findSpace(boxGrid[i], m-1);
        //     int j = space-1;
        //     if(space<0 || j<0){
        //         continue;
        //     }
        //     while(j>=0){
        //         if(boxGrid[i][j] == '#'){
        //             swap(boxGrid[i][j], boxGrid[i][space]);
        //             space = findSpace(boxGrid[i], space-1);
        //             // space = j;
        //         }
        //         else if(boxGrid[i][j] == '*'){
        //             space = findSpace(boxGrid[i], j-1);
        //             j = space;
        //         }
        //         j--;
        //     }
        // }
        boxGrid = rotate(boxGrid);
        return boxGrid;
    }
};