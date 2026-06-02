class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int minTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        for (int i = 0; i < n; i++) {
            int currTime = 0;
            currTime = abs(currTime - landStartTime[i]);
            currTime += landDuration[i];
            for (int j = 0; j < m; j++) {
                int waterTime = waterStartTime[j];
                if (waterTime <= currTime) {
                    minTime = min(minTime, waterDuration[j] + currTime);
                } else {
                    minTime = min(minTime, abs(waterTime - currTime) +
                                               currTime + waterDuration[j]);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int currTime = 0;
            currTime = abs(currTime - waterStartTime[i]);
            currTime += waterDuration[i];
            for (int j = 0; j < n; j++) {
                int waterTime = landStartTime[j];
                if (waterTime <= currTime) {
                    minTime = min(minTime, landDuration[j] + currTime);
                } else {
                    minTime = min(minTime, abs(waterTime - currTime) +
                                               currTime + landDuration[j]);
                }
            }
        }
        return minTime;
    }
};