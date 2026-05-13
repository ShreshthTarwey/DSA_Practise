class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>diff(2*limit+2, 0);
        for(int i=0;i<n/2;i++){
            diff[2] += 2;
            diff[2*limit+1] -= 2;
            //for moves = 1
            int a = nums[i];
            int b = nums[n-1-i];
            int minVal = min(a,b) + 1;
            int maxVal = max(a,b) + limit;
            diff[minVal] += (-1);
            diff[maxVal + 1] -= (-1);
            diff[a+b] += (-1);
            diff[a+b+1] -= (-1);
        }
        for(int i=1;i<2*limit+2;i++){
            diff[i] += diff[i-1];
        }
        int moves = INT_MAX;
        for(int i=2;i<2*limit+1;i++){
            moves = min(moves, diff[i]);
        }
        return moves;
    }
};