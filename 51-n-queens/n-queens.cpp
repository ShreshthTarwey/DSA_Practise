// class Solution {
// public:
//     bool isSafe(int row,int col,vector<string>& board,int n){
//         int dupRow = row;
//         int dupCol = col;
//         //Left upper diagonal koo check krr rhe hai
//         while(row>=0 && col>=0){
//             if(board[row][col]=='Q'){
//                 return false;
//             }
//             row--;
//             col--;
//         }
//         //Left downward diagonal check krr rhe hai
//         row = dupRow;
//         col = dupCol;
//         while(row<n && col>=0){
//             if(board[row][col]=='Q'){
//                 return false;
//             }
//             row++;
//             col--;
//         }
//         //Left side check krr rhe hai
//         row = dupRow;
//         col = dupCol;
//         while(col>=0){
//             if(board[row][col]=='Q'){
//                 return false;
//             }
//             col--;
//         }
//         return true;
//     }
//     void solve(vector<vector<string>>& ans,vector<string> &board,int col, int n){

//         if(col==n){
//             ans.push_back(board);
//             return;
//         }


//         for(int row=0;row<n;row++){
//             if(isSafe(row,col,board,n)){
//                 board[row][col] = 'Q';
//                 solve(ans,board,col+1,n);
//                 board[row][col] = '.';
//             }
            
            
//         }
//     }
//     void brute_force_backtracking(vector<vector<string>> &ans,int n){
//         string s(n,'.');
        
//         vector<string>board(n); 
//         for(int i=0;i<n;i++){
//             board[i]=s;
//         }
//         solve(ans,board,0,n);
//     } 
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>>ans;
//         brute_force_backtracking(ans,n);
//         return ans;
//     }
// };

class Solution {
public:
    bool issafe(vector<string> &board , int r , int c , int n ){
        for(int i=0 ; i<n ; i++){
            if(board[r][i]=='Q') return false ;
        }
        for(int i=0 ; i<n ; i++){
            if(board[i][c]=='Q') return false ;
        }
        for(int i=r , j=c ; i>=0 && j>=0 ; i--,j--){
            if(board[i][j]=='Q') return false ;
        }
        for(int i=r , j=c ; i>=0 && j<n ; i--,j++){
            if(board[i][j]=='Q') return false ;
        }
        return true ;
    }
    void sol(vector<string> & board , int row , int n , vector<vector<string>> & allpos){
        if(row==n){
            allpos.push_back(board);
        }
        for(int j= 0 ; j<n ;j++){
            if(row<n &&  (issafe(board,row,j, n))){
                board[row][j]='Q';
                sol(board , row+1 ,n,allpos );
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board (n , string(n, '.'));
        vector<vector<string>> allpos ;
        sol(board , 0 ,n, allpos);
        return allpos;
    }
};