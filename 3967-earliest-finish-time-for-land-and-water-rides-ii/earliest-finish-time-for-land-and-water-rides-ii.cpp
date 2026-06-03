class Solution {
public:
    int findFinishTime(vector<int>& start1, vector<int>& dur1, vector<int>& start2, vector<int>& dur2){
        int n = start1.size();
        int m = start2.size();
        int finish1 = INT_MAX;
        for(int i=0;i<n;i++){
            finish1 = min(finish1, start1[i]+dur1[i]);
        }
        int finish2 = INT_MAX;
        for(int i=0;i<m;i++){
            finish2 = min(finish2, max(finish1, start2[i]) + dur2[i]);
        }
        return finish2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int result1 = findFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
        int result2 = findFinishTime(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(result1, result2);
    }
};