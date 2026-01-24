class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // vector<int>ans(n, 0);
        vector<int>diff(n, 0);
        int m = bookings.size(); 
        for(int i=0;i<m;i++){
            int index1 = bookings[i][0]-1;
            int index2 = bookings[i][1]-1;
            int val = bookings[i][2];
            diff[index1] += val;
            if(index2+1<n){
                diff[index2+1] -= val;
            }
        }

        //Doing prefix sum
        for(int i=1;i<n;i++){
            diff[i] += diff[i-1];
        }

        return diff;

    }
};