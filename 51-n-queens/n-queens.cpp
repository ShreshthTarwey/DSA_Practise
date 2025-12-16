class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        int dupRow = row;
        int dupCol = col;
        //Left upper  diagonal
        while(row>=0  && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row = dupRow;
        col = dupCol;
        //left downward diagonal

        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        row = dupRow;
        col = dupCol;

        //Left

        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

        return true;

    }
    void solve(vector<vector<string>>& ans, vector<string>&board, int col, int n){
        if(col==n) ans.push_back(board);
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(ans, board, col+1, n);
                board[row][col] = '.';
            }
        }
    }
    void backtracking(vector<vector<string>>&ans, int n){
        string s(n, '.');
        vector<string>board(n);
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(ans, board, 0, n);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        backtracking(ans, n);
        return ans;
    }
};