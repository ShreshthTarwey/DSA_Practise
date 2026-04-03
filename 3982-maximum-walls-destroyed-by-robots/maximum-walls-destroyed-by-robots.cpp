class Solution {
public:
    int count(vector<int>& walls, int l, int r){
        int rightIndex = upper_bound(walls.begin(), walls.end(), r) - walls.begin();
        int leftIndex = lower_bound(walls.begin(), walls.end(), l) - walls.begin();

        return rightIndex - leftIndex;
    }
    int recFun(vector<int>& walls, vector<pair<int, int>>&  roboDist, vector<pair<int, int>>& range, int idx, int dir, vector<vector<int>>& dp){
        if(idx>=roboDist.size()){
            return 0;
        }
        if(dp[idx][dir]!=-1) return dp[idx][dir];
        int leftRange = range[idx].first;
        if(dir == 1){
            leftRange = max(leftRange, range[idx-1].second+1);
        }
        int rightRange = range[idx].second;
        int fireLeft = count(walls, leftRange, roboDist[idx].first) + recFun(walls, roboDist, range, idx+1, 0, dp);
        int fireRight = count(walls, roboDist[idx].first, rightRange) + recFun(walls, roboDist, range, idx+1, 1, dp);

        return dp[idx][dir] =  max(fireLeft, fireRight);
    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        sort(walls.begin(), walls.end());
        vector<pair<int,int>>roboDist;
        int n = robots.size();
        for(int i=0;i<n;i++){
            roboDist.push_back({robots[i], distance[i]});
        }
        sort(roboDist.begin(), roboDist.end());
        vector<pair<int, int>>range;
        for(int i=0;i<n;i++){
            int l0 = roboDist[i].first - roboDist[i].second ;
            int r0 = roboDist[i].first + roboDist[i].second ;
            if(i-1>=0){
                l0 = max(l0, roboDist[i-1].first+1);
            }
            if(i+1<n){
                r0 = min(r0, roboDist[i+1].first - 1);
            }
            range.push_back({l0, r0});
        }
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return recFun(walls, roboDist, range, 0, 0, dp);
    }
};