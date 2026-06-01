class Solution {
public:
    int minimumCost(vector<int>& cost) {
        auto comparator = [&](int a, int b){
            return a>b;
        };
        sort(cost.begin(), cost.end(), comparator);
        int ans = 0;
        int n = cost.size();
        int i = 0;
        while(i<n){
            ans += cost[i++];
            if(i>=n) break;
            ans += cost[i++];
            i++;
        }
        return ans;
    }
};