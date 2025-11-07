class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n){
        int dupRow = row;
        int dupCol = col;
        //Left upper diagonal koo check krr rhe hai
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        //Left downward diagonal check krr rhe hai
        row = dupRow;
        col = dupCol;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        //Left side check krr rhe hai
        row = dupRow;
        col = dupCol;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        return true;
    }
    void solve(vector<string>& temp, int &count, int col){
        //Base case
        if(col == temp.size()){
            count++;
            return;
        }

        int n = temp.size();
        for(int row = 0;row<n;row++){
            if(isSafe(row,col,temp,temp.size())){
                temp[row][col] = 'Q';
                solve(temp, count, col+1);
                temp[row][col] = '.';
            }
        }
    }
    int backtracking_method(int n){
        vector<string>temp;
        string s(n, '.');
        for(int i=0;i<n;i++){
            temp.push_back(s);
        }
        int count = 0;
        solve(temp, count,0);
        return count;
    }
    int totalNQueens(int n) {
        // return 0;
        return backtracking_method(n);
    }
};