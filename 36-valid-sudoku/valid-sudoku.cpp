class Solution {
public:
    bool checkFun(vector<vector<char>>& board, int i, int j, char target){
        //checking right
        for(int k=j+1;k<board.size();k++){
            if(target==board[i][k]){
                return false;
            }
        }

        //checking down

        for(int k=i+1;k<board.size();k++){
            if(target==board[k][j]) return false;
        }

        //Finding 3x3
        for(int k=0;k<board.size();k++){
            int row = 3*(i/3) + k/3;
            int col = 3*(j/3) + k%3;
            if (row == i && col == j) continue;
            if(board[row][col] == target) return false;
        }

        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if (board[i][j] == '.') continue;
                bool check = checkFun(board, i, j, board[i][j]);
                if(!check) return false;
            }
        }
        return true;
    }
};