class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks, int amount){
        for(auto &task: tasks){
            if(task[1]>amount || task[0] > amount){
                return false;
            }
            amount -= task[0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int l = 0;
        int r = 1e9;
        int result = 0;
        sort(tasks.begin(), tasks.end(), [](auto task1, auto task2){
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];
            return diff1 > diff2;
        });
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPossible(tasks, mid)){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return result;
    }
};