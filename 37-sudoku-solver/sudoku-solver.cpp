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
    bool solve(vector<vector<char>>& board){
        //Base Case ???


        //1 Case solve krr rhe hai
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                //Kya current cell empty hai?
                if(board[i][j] == '.'){
                    //1 -> 9 digits place krr kai dekho
                    for(int k=1;k<=9;k++){
                        if(isSafe(board,k + '0',i,j)){
                            board[i][j] = k+'0';
                            bool aageSolveHoPaya = solve(board);

                            if(aageSolveHoPaya){
                                return true;
                            }
                            else{
                                //BackTrack
                                board[i][j] = '.';
                            }
                        }
                    }
                    //Agar koi digit nhi satisfy krr paiy to matlab pahale kuch galti hui hai to false return kro
                    return false;
                }
            }
        }

        //Agar yaha tkk pauch gaye hai toh matlab sari cells fill hoo gai and pura sudoku solve hoo gaya 
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};