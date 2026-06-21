class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n-1});
        sort(restrictions.begin(), restrictions.end());
        int size = restrictions.size();
        //Left to right correction
        for(int i=1;i<size;i++){
            int dist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], dist+restrictions[i-1][1]);
        }
        //Right to left;
        for(int i=size-2;i>=0;i--){
            int dist = restrictions[i+1][0] - restrictions[i][0]; 
            restrictions[i][1] = min(restrictions[i][1], dist+restrictions[i+1][1]);
        }
        //Finding the answer
        int ans = 0;
        for(int i=1;i<size;i++){
            int leftPos = restrictions[i-1][0];
            int leftHeight = restrictions[i-1][1];

            int rightPos = restrictions[i][0];
            int rightHeight = restrictions[i][1];
            int dist = rightPos - leftPos;
            int diff = abs(leftHeight - rightHeight);
            ans = max(ans, max(leftHeight, rightHeight) + (dist - diff)/2);
        }
        return ans;
    }
};