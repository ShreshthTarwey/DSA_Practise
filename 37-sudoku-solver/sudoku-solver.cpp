class Solution {
public:

     bool isSafe(vector<vector<char>>& board, char digit,int i, int j){
        int n = board.size();
        //Checking for row
        for(int k=0;k<n;k++){
            if(board[i][k] == digit){
                return false;
            } 
        }

        //Checking for column
        for(int k=0;k<n;k++){
            if(board[k][j] == digit){
                return false;
            }
        }

        //Checking for 3x3 box

        for(int k=0;k<n;k++){
            int row = 3*(i/3) + k/3;
            int col = 3*(j/3) + k%3;
            if(board[row][col] == digit){
                return false;
            }
        }

        return true;
    }
    bool backtrackingMethod(vector<vector<char>>& board){
        int n = board.size();
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(board[row][col] == '.'){
                    for(int i=1;i<=9;i++){
                        if(isSafe(board, i+'0', row,col)){
                            board[row][col] = i+'0';
                            bool aageSolveHua = backtrackingMethod(board);

                            if(aageSolveHua) return true;

                            else board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrackingMethod(board);
    }
};