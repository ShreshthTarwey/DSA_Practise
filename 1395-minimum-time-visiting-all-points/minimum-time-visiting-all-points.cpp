class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int moves = 0;
        for(int i=0;i<points.size()-1;i++){
            int x1 = points[i][0];
            int x2 = points[i+1][0];
            int y1 = points[i][1];
            int y2 = points[i+1][1];
            moves+= max(abs(x1-x2), abs(y1-y2));
        }
        return moves;
    }
};