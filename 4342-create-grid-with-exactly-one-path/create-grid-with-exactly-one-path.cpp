class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string str(n, '#');
        vector<string>result(m, str);
        int i = 0;
        int j = 0;
        while(i<m){
            result[i][j] = '.';
            i++;
        }
        i--;
        while(j<n){
            result[i][j] = '.';
            j++;
        }
        return result;
    }
};