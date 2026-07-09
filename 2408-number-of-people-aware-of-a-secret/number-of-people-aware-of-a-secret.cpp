class Solution {
public:
    const int MOD = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<pair<int, int>>forgetQ,delayQ;
        int curr = 0;
        int ans = 1;
        forgetQ.push({1,1});
        delayQ.push({1,1});
        for(int i=1;i<=n;i++){
            auto p = forgetQ.front();
            if(p.first + forget <= i){
                forgetQ.pop();
                ans = (ans - p.second + MOD)%MOD;
                curr = (curr - p.second+MOD)%MOD;
            }
            auto p1 = delayQ.front();
            if(p1.first + delay <= i){
                curr = (curr + p1.second)%MOD;
                delayQ.pop();
            }
            if(curr>0){
                ans = (ans + curr)%MOD;
                forgetQ.push({i, curr});
                delayQ.push({i, curr});
            }
        }
        return ans;
    }
};