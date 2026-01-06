class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col, char target){
        //Right side check
        for(int j = col+1;j<board.size();j++){
            if(board[row][j]==target){
                return false;
            }
        }

        //down side check
        for(int j=row+1;j<board.size();j++){
            if(board[j][col]==target){
                return false;
            }
        }

        //3x3 check
        for(int k=0;k<board.size();k++){
            int row1 = 3*(row/3) + k/3;
            int col1 = 3*(col/3) + k%3;
            if(row1 == row || col1 == col){
                continue;
            }
            if(board[row1][col1] == target) return false;

        }

        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.') continue;
                if(check(board, i,j,board[i][j])){
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};