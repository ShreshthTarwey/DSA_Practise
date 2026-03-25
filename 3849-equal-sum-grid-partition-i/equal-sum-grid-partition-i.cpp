class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long>leftPrefix1(m);
        vector<long long>leftPrefix2(n);
    
        //Column by Column Sum
        for(int j=0;j<m;j++){
            long long sum = 0;
            for(int i=0;i<n;i++){
                sum+=grid[i][j];
            }
            leftPrefix1[j] = sum;
        }


        //Row by Row Sum
        for(int i=0;i<n;i++){
            long long sum = 0;
            for(int j=0;j<m;j++){
                sum += grid[i][j];
            }
            leftPrefix2[i] = sum;
        }

        //Checking for vertical cut
        vector<long long>temp = leftPrefix1;
        for(int j=1;j<m;j++){
            temp[j] += temp[j-1];
        }
        long long r = 0;
        for(int j=m-1;j>=0;j--){
            if(r == temp[j]){
                return true;
            }
            r += leftPrefix1[j];
        }

        //Checking for Horizontal Cut;

        vector<long long>temp2 = leftPrefix2;
        for(int i=1;i<n;i++){
            temp2[i] += temp2[i-1];
        }
        r = 0;
        for(int i=n-1;i>=0;i--){
            if(r == temp2[i]){
                return true;
            }
            r += leftPrefix2[i];
        }

        return false;
    }
};