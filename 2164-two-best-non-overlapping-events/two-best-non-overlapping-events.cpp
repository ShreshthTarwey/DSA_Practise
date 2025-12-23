class Solution {
public:
    int binarySearch(vector<vector<int>>& events, int endTime){
        int l = 0;
        int h = events.size()-1;
        int ans = events.size();
        while(l<=h){
            int mid = l + (h-l)/2;
            if(events[mid][0]>endTime){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int recFun(vector<vector<int>>& events, int index, int count, vector<vector<int>>& dp){
        //Base Case
        if(count>=2) return 0;
        if(index>=events.size()) return 0;
        if(dp[index][count] != -1) return dp[index][count];
        int pick = 0;
        
            int nextIndex = binarySearch(events, events[index][1]);
            pick = events[index][2] + recFun(events, nextIndex, count+1, dp);
        
        int notPick = recFun(events, index+1, count, dp);

        return dp[index][count] = max(pick, notPick);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>>dp(events.size(), vector<int>(2, -1));
        sort(events.begin(), events.end());
        return recFun(events, 0, 0, dp);
    }
};