class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost = 0;
        int row = startPos[0];
        int col = startPos[1];
        int targetRow = homePos[0];
        int targetCol = homePos[1];
        int n = rowCosts.size();
        int m = colCosts.size();
        // if(row>targetRow){
        //     swap(row, targetRow);
        // }
        // if(col>targetCol){
        //     swap(col, targetCol);
        // }
        if(row<=targetRow){
            row++;
            while(row<n && row<=targetRow){
                cost+=rowCosts[row];
                row++;
            }
        }
        else{
            row--;
            while(row<n && row>=targetRow){
                cost+=rowCosts[row];
                row--;
            }
        }

        if(col<=targetCol){
            col++;
            while(col<m && col<=targetCol){
                cost+=colCosts[col];
                col++;
            }
        }
        else{
            col--;
            while(col<m && col>=targetCol){
                cost+=colCosts[col];
                col--;
            }
        }
        return cost;
    }
};