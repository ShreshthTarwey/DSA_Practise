class Solution {
public:
    double area_below(double mid, vector<vector<int>>& squares){
        double area = 0;
        for(int i=0;i<squares.size();i++){
               int x1 = squares[i][0];
               double y1 = squares[i][1];
               double li = squares[i][2];
               //Case 1-> square below Y
               if(y1+li<=mid){
                area+= li*li;
                continue;
               }
               //Case2->square between Y
                if(mid>y1 && mid<y1+li){
                    area+= (mid-y1) * li;
                }
        }
        return area;
    }
    double area_above(double mid, vector<vector<int>>& squares){
        double area = 0;
        for(int i=0;i<squares.size();i++){
               int x1 = squares[i][0];
               int y1 = squares[i][1];
               int li = squares[i][2];
               //Case 1-> square above Y
               if(y1>=mid){
                area+= li*li;
                continue;
               }
               //Case2->square between Y
                if(mid>y1 && mid<y1+li){
                    // area+= (xi+li-mid) * (xi+li-mid);
                    area+= (y1+li-mid) * li;
                }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0;
        double high = (double)1e9;
        int repeat = 60;
        double totalArea = 0;
        for(int i=0;i<squares.size();i++){
            double li = squares[i][2];
            totalArea+= (li*li);
        }
        while(repeat--){
            double mid = (low+high)/2;
            double areaBelow = area_below(mid, squares);
            // double areaAbove = area_above(mid, squares);
            if(areaBelow<(totalArea-areaBelow)){
                low = mid;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};