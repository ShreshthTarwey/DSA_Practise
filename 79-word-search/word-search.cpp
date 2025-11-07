class Solution {
public:
    bool backtracking_method(vector<vector<char>>& board, string word, int row, int col, int index){
        //Base Case
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return false;

        if(index>=word.length()){
            return true;
        }
        // cout<<"Checkpoint2"<<endl;
        if(board[row][col] != word[index]) return false;

        char temp = board[row][col];

        board[row][col] = '#';

        bool found = backtracking_method(board, word, row, col+1, index+1) || 
                     backtracking_method(board, word, row+1, col, index+1) ||
                     backtracking_method(board, word, row, col-1, index+1) ||
                     backtracking_method(board, word, row-1, col, index+1);
        // cout<<found<<" Checkpoint3"<<endl;

        //Backtrack
        board[row][col] = temp;
        return found; 


        
    
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row =  0;
        int col = 0;
        int string_index = 0;
        if(board.size() ==1 && board[0].size()==1){
            string temp = "";
            temp+=board[0][0];
            return temp == word;
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    // cout<<"Checkpoint1"<<endl;
                    if(backtracking_method(board, word, i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};