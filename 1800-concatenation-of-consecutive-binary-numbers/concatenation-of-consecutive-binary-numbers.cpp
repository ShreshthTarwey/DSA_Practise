class Solution {
public:
    const int MOD = 1e9+7;
    int concatenatedBinary(int n) {
        long long res = 0;
        for(int i=1;i<=n;i++){
            int digits = log2(i) + 1;
            res = ((res<<digits)%MOD + i)%MOD;
        }
        return res;
    }
};