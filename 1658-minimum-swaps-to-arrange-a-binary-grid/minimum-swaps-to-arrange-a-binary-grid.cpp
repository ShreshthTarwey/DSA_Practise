class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int>maxRights;
        int n = grid.size();
        for(int i=0;i<n;i++){
            int maxRight = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    maxRight = j;
                }
            }
            maxRights.push_back(maxRight);
        }
        //Now we have maxRights off all the rows, for row i maxRight should be <= i
        int count = 0;
        for(int i=0;i<n-1;i++){
            int target = i;
            int found = -1;
            //Find first 
            for(int j=i;j<n;j++){
                if(maxRights[j]<=target){
                    found = j;
                    break;
                }
            }
            //Now count number of swaps
            if(found==-1) return -1;

            while(found>i && found>0){
                swap(maxRights[found], maxRights[found-1]);
                count++;
                found--;
            }
        }
        return count;
    }
};