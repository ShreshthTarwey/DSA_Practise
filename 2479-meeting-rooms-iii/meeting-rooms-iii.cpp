class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        map<int,long long>mp;
        vector<int>ansArr(n, 0);
        //Filling the map
        sort(meetings.begin(), meetings.end());
        for(int i=0;i<n;i++){
            mp[i] = 0;
        }

        for(int i=0;i<meetings.size();i++){
            long long startTime = meetings[i][0];
            long long duration = meetings[i][1] - meetings[i][0];
            long long minTime = LLONG_MAX;
            int minIndex = -1;
            bool flag = false;
            for(auto it: mp){
                if(it.second<=startTime){
                    ansArr[it.first]++;
                    mp[it.first] = max(it.second + duration, (long long)meetings[i][1]);
                    flag = true;
                    break;
                }
                else{
                    if(minTime>it.second){
                        minTime = min(minTime, it.second);
                        minIndex = it.first;
                    }
                }
            }

            if(!flag){
                mp[minIndex] = minTime + duration;
                ansArr[minIndex]++;
            }

        }

        auto it = max_element(ansArr.begin(), ansArr.end());

        return distance(ansArr.begin(), it);

    }
}; 