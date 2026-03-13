class Solution {
public:
    bool check(int mountainHeight, vector<int>& workerTimes, long long sec){
        long long height = 0;
        for(auto it: workerTimes){
            // int x = 1;
            // while(true){
            //     long long num = 1LL * it * (1ll * x * (x+1))/2;
            //     if(num>sec){
            //         height += x-1;
            //         break;
            //     }
            //     x++;
            // }
            long long k = (1ll * 2 * sec)/it;
            long long x = (sqrtl(1 + 4.0*k) - 1)/2;
            height += x;
        }
        return height>=mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 1;
        long long r = 1e18;
        long long result = -1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(check(mountainHeight, workerTimes, mid)){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};