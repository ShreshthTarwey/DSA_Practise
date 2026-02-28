class Solution {
public:
    const int MOD = 1e9+7;
    int method1(int n){
        long long res = 0;
        for(int i=1;i<=n;i++){
            int digits = log2(i) + 1; //Remember it, how much digit or bits it will take to represent any number
            res = ((res<<digits)%MOD + i)%MOD;
        }
        return res;
    }
    int method2(int n){
        long long res = 0;
        int bits = 0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0){
                bits++;
            }
            res = ((res<<bits)%MOD + i) % MOD;
        }
        return res;
    }
    int concatenatedBinary(int n) {
        // return method1(n); //This is for the one who remembers how to calculate how much bit a number will take to represent
        return method2(n);
    }
};